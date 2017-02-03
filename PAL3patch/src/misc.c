// misc functions
#include "common.h"


int is_win9x()
{
    OSVERSIONINFO osvi;
    memset(&osvi, 0, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);
    GetVersionEx(&osvi);
    return osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS;
}

int str2int(const char *valstr)
{
    int result, ret;
    ret = sscanf(valstr, "%d", &result);
    if (ret != 1) fail("can't parse '%s' to integer.", valstr);
    return result;
}

double str2double(const char *valstr)
{
    int ret;
    double result;
    ret = sscanf(valstr, "%lf", &result);
    if (ret != 1) fail("can't parse '%s' to double.", valstr);
    return result;
}

int str_iendwith(const char *a, const char *b)
{
    int lena = strlen(a), lenb = strlen(b);
    return lena >= lenb && stricmp(a + lena - lenb, b) == 0;
}

double fbound(double x, double low, double high)
{
    return fmin(fmax(x, low), high);
}

int fcmp(double a, double b)
{
    double d = a - b;
    if (fabs(d) <= eps) return 0;
    return d > 0 ? 1 : -1;
}

HMODULE LoadLibrary_safe(LPCTSTR lpFileName)
{
    HMODULE ret = LoadLibrary(lpFileName);
    if (!ret) fail("can't load library '%s'.", lpFileName);
    return ret;
}

FARPROC GetProcAddress_safe(HMODULE hModule, LPCSTR lpProcName)
{
    FARPROC ret = GetProcAddress(hModule, lpProcName);
    if (!ret) fail("can't find proc address for '%s'.", lpProcName);
    return ret;
}

// convert a c-string to c-wide-string, alloc memory, don't forget to free()
wchar_t *cs2wcs(const char *cstr, UINT src_cp)
{
    wchar_t *ret;
    size_t len;
    
    // get string length first
    len = MultiByteToWideChar(src_cp, 0, cstr, -1, NULL, 0);
    if (len == 0) goto fail;
    
    // alloc buffer
    ret = malloc(sizeof(wchar_t) * len);
    if (!ret) goto fail;
    
    MultiByteToWideChar(src_cp, 0, cstr, -1, ret, len);
    return ret;
    
fail:
    // no need to free(ret)
    return wcsdup(L"cs2wcs failed.");
}

void NORETURN __fail(const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buf[MAXLINE];
    char msgbuf[MAXLINE];
    int len;
    snprintf(msgbuf, sizeof(msgbuf), "  file: %s\n  line: %d\n  func: %s\nmessage:\n  ", file, line, func);
    len = strlen(msgbuf);
    vsnprintf(msgbuf + len, sizeof(msgbuf) - len, fmt, ap);
    OutputDebugString(msgbuf);
    FILE *fp = fopen(ERROR_FILE, "w");
    if (fp) {
        fputs("build information:\n", fp);
        fputs(build_info, fp);
        
        get_all_config(buf, sizeof(buf));
        fputs("patch configuration:\n", fp);
        fputs(buf, fp);
        
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);
        snprintf(buf, sizeof(buf), "  %04hu-%02hu-%02hu %02hu:%02hu:%02hu.%03hu\n", SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliseconds);
        fputs("timestamp:\n", fp);
        fputs(buf, fp);
        
        fputs("error details:\n", fp);
        fputs(msgbuf, fp);
        fputc('\n', fp);
        fclose(fp);
    }
    try_goto_desktop();
    MessageBoxA(NULL, msgbuf + len, "PAL3patch", MB_ICONERROR | MB_TOPMOST | MB_SETFOREGROUND);
    TerminateProcess(GetCurrentProcess(), 1);
    while (1);
    va_end(ap);
}

static long long plog_lines = 0;
static long long plog_msgboxes = 0;
void __plog(int is_warning, const char *file, int line, const char *func, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buf[MAXLINE];
    char msgbuf[MAXLINE];
    int len;
    snprintf(msgbuf, sizeof(msgbuf), "  file: %s\n  line: %d\n  func: %s\nmessage:\n  ", file, line, func);
    len = strlen(msgbuf);
    vsnprintf(msgbuf + len, sizeof(msgbuf) - len, fmt, ap);
    OutputDebugString(msgbuf);
    plog_lines++;
    if (plog_lines <= MAXLOGLINES) {
        FILE *fp = fopen(WARNING_FILE, plog_lines > 1 ? "a" : "w");
        if (fp) {
            if (plog_lines == 1) {
                fputs("build information:\n", fp);
                fputs(build_info, fp);
                
                get_all_config(buf, sizeof(buf));
                fputs("patch configuration:\n", fp);
                fputs(buf, fp);
                fputs("========== start ==========\n\n", fp);
            }
            
            SYSTEMTIME SystemTime;
            GetLocalTime(&SystemTime);
            snprintf(buf, sizeof(buf), "  %04hu-%02hu-%02hu %02hu:%02hu:%02hu.%03hu\n", SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond, SystemTime.wMilliseconds);
            fputs("timestamp:\n", fp);
            fputs(buf, fp);
            
            fputs("details:\n", fp);
            fputs(msgbuf, fp);
            fputs("\n\n\n", fp);
            if (plog_lines >= MAXLOGLINES) {
                fputs("too many messages, log truncated.\n", fp);
            }
            fclose(fp);
        }
        if (is_warning) {
            plog_msgboxes++;
            if (plog_msgboxes <= MAXWARNMSGBOXES) {
                if (plog_msgboxes >= MAXWARNMSGBOXES) {
                    strncat(msgbuf, "\n\nmax messagebox limit reached.", sizeof(msgbuf) - strlen(msgbuf));
                    msgbuf[sizeof(msgbuf) - 1] = '\0';
                }
                try_goto_desktop();
                MessageBoxA(NULL, msgbuf + len, "PAL3patch", MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
            }
        }
    }
    
    va_end(ap);
}
