#include "stdafx.h"

/*
	格式指导：
		数字字母使用半角字符，标点符号使用全角字符
		西文字符序列两侧若不是标点，两侧须加空格
		第二人称使用“您”
		一句话以句号结尾
*/

ConfigDescItem ConfigDescList_CHS[] = {
	{
		0, FALSE, TRUE,
		NULL,
		_T("欢迎"),

#ifdef BUILD_FOR_PAL3
		_T("欢迎使用《仙剑奇侠传三》分辨率补丁 ")
#endif
#ifdef BUILD_FOR_PAL3A
		_T("欢迎使用《仙剑三外传·问情篇》分辨率补丁 ")
#endif
			PATCH_VERSION _T("\r\n")
			_T("本补丁可以扩大游戏的分辨率，\r\n")
			_T("同时修复一些游戏程序的小问题，\r\n")
			_T("并且添加了一些实用的小功能。"),
		_T("请选择左侧栏中的条目进行操作。"),
	},
	{
		0, FALSE, TRUE,
		NULL,
		_T("常规设置"),
		_T(""),
		_T(""),
	},
	{
		1, FALSE, TRUE,
		_T("showabout"),
		_T("显示关于"),
		_T("是否在游戏程序启动时显示本补丁的“关于”窗口。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏程序启动后将直接进入游戏画面。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，游戏程序启动时会弹出本补丁的“关于”窗口。"), _T("1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("showfps"),
		_T("显示帧率"),
		_T("本选项可以在游戏界面左上角显示游戏帧率、补丁版本和帧时抖动信息。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏不会显示帧率。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，补丁会在左上角显示游戏帧率、补丁版本和帧时抖动信息。"), _T("1") },
		}
	},
	{
		0, FALSE, TRUE,
		NULL,
		_T("图形设置"),
		_T(""),
		_T(""),
	},
	{
		1, FALSE, TRUE,
		_T("game_resolution"),
		_T("分辨率"),
		_T("此选项可以调节游戏的分辨率。\r\n格式为：宽度x高度"),
		NULL,
		NULL,
		{ { NULL } },
		EnumDisplayMode,
	},
	{
		1, FALSE, TRUE,
		_T("game_windowed"),
		_T("窗口化"),
		_T("此选项可以使游戏以窗口模式运行。"),
		NULL,
		NULL,
		{
			{ _T("全屏幕"), _T("选择此项后，游戏将以全屏幕方式运行。"), _T("0") },
			{ _T("窗口模式"), _T("选择此项后，游戏将以窗口模式运行。"), _T("1") },
			{ _T("窗口模式（无边框）"), _T("选择此项后，游戏将以无边框的窗口模式运行。"), _T("2") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("game_zbufferbits"),
		_T("深度缓存"),
		_T("此选项可以调节游戏的深度缓存级别。\r\n格式为：位数 （位数一般为 16 或 24）\r\n注意：由于游戏只使用深度缓存而没有使用模板缓存，因此启用模板缓存没有意义。"),
		NULL,
		NULL,
		{ { NULL } },
		EnumDepthBuffer,
	},
	{
		1, FALSE, TRUE,
		_T("game_multisample"),
		_T("抗锯齿"),
		_T("此选项可以调节游戏的抗锯齿级别。\r\n格式为：级别,子等级 （子等级一般设为 0）"),
		NULL,
		NULL,
		{ { NULL } },
		EnumMultisample,
	},
	{
		1, FALSE, TRUE,
		_T("clipcursor"),
		_T("捕获鼠标"),
		_T("是否启用鼠标捕获功能。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，鼠标可以随意移动。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，鼠标移动范围仅限游戏区域。\r\n注意：按 F12 键可以暂时禁用鼠标捕获功能。"), _T("1") },
		}
	},
	{
		1, FALSE, TRUE,
		_T("reduceinputlatency"),
		_T("减少延迟"),
		_T("本选项可以减少输入延迟（即鼠标接收到动作到动作被显示到显示器上的延迟），也有助于减少帧时抖动，但会有少量性能开销。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏输入延迟将为默认状态。"), _T("0") },
			{ _T("模式 1"), _T("选择此选项后，游戏会尽量降低输入延迟。该模式较为占用 CPU 资源。"), _T("1") },
			{ _T("模式 2"), _T("选择此选项后，游戏会尽量降低输入延迟。该模式较为占用显卡资源。"), _T("2") },
		}
	},
	{
		0, TRUE, TRUE,
		NULL,
		_T("字体设置"),
		_T(""),
		_T(""),
	},
	{
		1, TRUE, TRUE,
		_T("uireplacefont_facename"),
		_T("字体"),
		_T("指定游戏使用的字体。"),
		NULL,
		NULL,
		{ { NULL } },
		EnumFontface,
	},
	{
		1, TRUE, TRUE,
		_T("uireplacefont_bold"),
		_T("加粗"),
		_T("指定字体是否要加粗。"),
		NULL,
		NULL,
		{
			{ _T("常规"), _T("选择此项后，文字不会加粗。"), _T("0,0,0") },
			{ _T("加粗"), _T("选择此项后，文字会加粗。"), _T("1,1,1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("uireplacefont_quality"),
		_T("质量"),
		_T("指定字体的输出质量。"),
		NULL,
		NULL,
		{
			{ _T("锐利"), _T("选择此项后，不启用文字抗锯齿。"), _T("0") },
			{ _T("平滑"), _T("选择此项后，启用文字抗锯齿。"), _T("1") },
			{ _T("自动"), _T("选择此项后，自动选择相对更清晰的方式输出。"), _T("2") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("uireplacefont_preloadfontset"),
		_T("预加载"),
		_T("指定是否要预加载字体。"),
		NULL,
		NULL,
		{
			{ _T("不预加载字体"), _T("选择此项后，不预加载任何大小的字体，游戏可能会在显示文字时卡顿。"), _T("0") },
			{ _T("预加载剧情字体"), _T("选择此项后，只预加载剧情文字使用的字体大小。"), _T("1") },
			{ _T("预加载主要字体"), _T("选择此项后，只预加载主要使用的字体大小。"), _T("2") },
		}
	},
	{
		0, TRUE, TRUE,
		NULL,
		_T("用户界面设置"),
		_T(""),
		_T(""),
	},
	{
		1, TRUE, TRUE,
		_T("uiscalefactor"),
		_T("系统界面大小"),
		_T("此选项可以调整游戏系统界面（如欢迎界面、状态界面、交易界面等）的大小。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，系统界面将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，系统界面将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，系统界面将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("softcursor_scalefactor"),
		_T("软件光标大小"),
		_T("此选项可以调整软件光标（鼠标指针）的大小。该选项仅在开启软件光标时有效。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，软件光标将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，软件光标将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，软件光标将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		1, TRUE, TRUE,
		NULL,
		_T("战斗界面设置"),
		_T(""),
		_T(""),
	},
	{
		2, TRUE, TRUE,
		_T("fixcombatui_scalefactor"),
		_T("元素大小"),
		_T("此选项可以调整战斗界面元素（如按钮、列表等）的大小。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，战斗界面元素将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，战斗界面元素将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，战斗界面元素将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		2, TRUE, TRUE,
		_T("fixcombatui_scaletype"),
		_T("界面范围"),
		_T("指定战斗界面占用屏幕的范围。"),
		NULL,
		NULL,
		{
			{ _T("无边缘"), _T("选择此项后，屏幕两侧没有留白。"), _T("full") },
			{ _T("有边缘"), _T("选择此项后，在宽屏分辨率下，屏幕两侧会有留白，以保证操作区域的 4:3 比例。"), _T("full43") },
		}
	},
	{
		1, TRUE, TRUE,
		NULL,
		_T("场景界面设置"),
		_T(""),
		_T(""),
	},
	{
		2, TRUE, TRUE,
		_T("fixsceneui_uiscalefactor"),
		_T("元素大小"),
		_T("指定场景用户界面元素的大小。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，场景用户界面元素将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，场景用户界面元素将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，场景用户界面元素将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		2, TRUE, TRUE,
		_T("fixsceneui_textscalefactor"),
		_T("文字大小"),
		_T("指定场景界面文字（如剧情文字等）的大小。此选项会间接影响剧情对话框的大小。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，场景界面文字将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，场景界面文字将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，场景界面文字将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		2, TRUE, TRUE,
		_T("fixsceneui_iconscalefactor"),
		_T("图标大小"),
		_T("指定场景界面图标（如动画表情等）的大小。"),
		NULL,
		NULL,
		{
			{ _T("小"), _T("选择此项后，场景界面图标将按照最大 50% 比例放大。"), _T("small") },
			{ _T("中"), _T("选择此项后，场景界面图标将按照最大 75% 比例放大。"), _T("medium") },
			{ _T("大"), _T("选择此项后，场景界面图标将按照 100% 比例放大。"), _T("large") },
		}
	},
	{
		2, TRUE, TRUE,
		_T("fixsceneui_scaletype"),
		_T("界面范围"),
		_T("指定场景界面占用屏幕的范围。"),
		NULL,
		NULL,
		{
			{ _T("无边缘"), _T("选择此项后，屏幕两侧没有留白。"), _T("full") },
			{ _T("有边缘"), _T("选择此项后，在宽屏分辨率下，屏幕两侧会有留白，以保证操作区域的 4:3 比例。"), _T("full43") },
		}
	},
	{
		0, TRUE, TRUE,
		NULL,
		_T("高级设置"),
		_T(""),
		_T(""),
	},
#ifdef BUILD_FOR_PAL3A
	{
		1, TRUE, TRUE,
		_T("setpal3path"),
		_T("仙三安装路径"),
		_T("设置仙三安装路径，以便继承仙三存档。游戏会从此路径下的“save”文件夹内读取存档。"),
		_T("请在文本框内键入仙三安装路径（注意不是存档路径；长度须小于 256 字节）。若设为“autodetect”则会自动从注册表中获取。"),
	},
#endif
	{
		1, TRUE, TRUE,
		_T("cdpatch"),
		_T("免光盘补丁"),
		_T("是否启用本补丁内置的免光盘补丁。\r\n如果游戏启动时出现“Please Insert Disc4 to Driver X:”信息，建议启用本选项。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏将从注册表中读取光盘盘符信息。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，无须修改注册表，游戏程序就将直接从当前目录读取游戏数据。请确保您执行的是完整安装。"), _T("1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("regredirect"),
		_T("注册表重定向"),
		_T("注册表重定向功能可以将“前尘忆梦”和“小游戏”的通关状态重定向到“save/registry.txt”文件中。原始情况下，这些信息是存储在注册表中的。"),
		NULL,
		NULL,
		{
			{ _T("仅注册表"), _T("选择此项后，游戏将仅在注册表中读取/写入这些信息。"), _T("0") },
			{ _T("文件优先"), _T("选择此项后，游戏读取这些信息时，将首先尝试从文件中读取，若读取失败才从注册表中读取；写入信息时，将同时写入文件和注册表。"), _T("1") },
			{ _T("仅文件"), _T("选择此项后，游戏将仅在文件中读取/写入这些信息。"), _T("2") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("nocpk"),
		_T("免 CPK 补丁"),
		_T("原始情况下，游戏数据全部是压缩存放于数个 CPK 文件之中。本选项可以让游戏直接从文件系统读取游戏数据，而不是从 CPK 中读取。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏将从 CPK 中读取游戏数据。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，游戏将直接从文件系统读取游戏数据（启用前，需要将 CPK 解压缩并放置到正确位置）。"), _T("1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("console"),
		_T("调出控制台"),
		_T("原始情况下，需要输入“")
#ifdef BUILD_FOR_PAL3
		_T("sOFTsTAR_pAL3_2003")
#endif
#ifdef BUILD_FOR_PAL3A
		_T("SoftStar-PAL3A-2004-07-02")
#endif
		_T("”并按回车后才能调出控制台。本选项可以允许直接调出控制台（按 ~ 所在的按键）。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，需要输入密码才能调出控制台。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，可以直接按 ~ 键调出控制台。"), _T("1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("testcombat"),
		_T("战斗编辑器"),
		_T("是否启用游戏程序内置的战斗编辑器。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("禁用此选项后，游戏启动后将进入正常的游戏模式。"), _T("0") },
			{ _T("启用"), _T("启用此选项后，游戏启动后将进入战斗系统调试模式。建议同时启用免 CPK 补丁。此模式下不能进行正常游戏。"), _T("1") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("windowtitle"),
		_T("窗口标题"),
		_T("修改游戏窗口标题。某些修改器可能需要将标题设为原始标题（PAL3--SOFTSTAR.sh）才能正常工作。"),
		_T("请在文本框内键入您想使用的游戏窗口标题。（长度须少于 128 字节）"),
	},
	{
		1, TRUE, TRUE,
		_T("setlocale"),
		_T("区域设置"),
		_T("本选项可以修改程序运行时的语言区域。如果您在运行游戏时遇到游戏内文字乱码的问题，可以尝试使用此选项。"),
		NULL,
		NULL,
		{
			{ _T("自动"), _T("选择此选项后，补丁会自动检测游戏语言版本，并自动选择正确的字符编码。"), _T("3") },
			{ _T("简体中文"), _T("选择此选项后，无论操作系统语言版本如何，游戏都将使用简体中文编码显示字符。\r\n如果您使用的是简体版游戏，请选择此选项。"), _T("1") },
			{ _T("繁体中文"), _T("选择此选项后，无论操作系统语言版本如何，游戏都将使用繁体中文编码显示字符。\r\n如果您使用的是繁体版游戏，请选择此选项。"), _T("2") },
		}
	},
	{
		1, TRUE, TRUE,
		_T("loadplugins"),
		_T("外部插件"),
		_T("可以使用此选项控制分辨率补丁是否加载外部插件。启用本功能后，将在“plugins”目录下自动寻找并加载外部插件。通过插件框架，外部插件可以灵活地扩充本分辨率补丁的功能。"),
		NULL,
		NULL,
		{
			{ _T("禁用"), _T("选择此选项后，游戏在启动时不会加载任何外部插件。"), _T("0") },
			{ _T("启用"), _T("选择此选项后，游戏在启动时会自动寻找并加载外部插件。"), _T("1") },
		}
	},
	{
		0, FALSE, TRUE,
		NULL,
		_T("实用工具"),
		_T(""),
		_T(""),
	},
	{
		1, FALSE, TRUE,
		NULL,
		_T("恢复默认设置"),
		_T("此功能可以将所有补丁配置项全部恢复为默认值。官方配置工具中的配置项不会被改变。"),
		_T("如果您在修改配置文件或升级补丁版本后，遇到游戏启动时报错的情况，您可以尝试用此功能将补丁配置文件重置为初始状态。"),
		CPatchConfigDlg::RestoreAllConfigToDefault,
	},
	{
		1, FALSE, TRUE,
		NULL,
		_T("官方配置工具"),
		_T("此功能可以打开官方编写的游戏配置工具。使用它可以编辑“垂直同步”、“软件光标”等选项。"),
		_T("官方配置工具是游戏目录下的“config.exe”，相关的配置数据存储在“config.ini”文件内。")
#ifdef BUILD_FOR_PAL3A
		_T("注意：补丁的分辨率设置会覆盖官方工具的分辨率设置。")
#endif
		,
		OpenConfigTool,
	},
	{
		1, FALSE, TRUE,
		NULL,
		_T("打开存档目录"),
		_T("此功能可以打开游戏的存档目录。"),
		_T("通常情况下，游戏的存档储存于“save”文件夹下。但在某些特殊情况下，由于权限等原因，游戏存档可能并没有保存在该目录内。如果您遇到“在 save 目录下没找到存档”的情况，可以尝试使用此功能来查找存档。"),
		OpenSaveFolder,
	},
	{
		1, FALSE, TRUE,
		NULL,
		_T("打开截屏目录"),
		_T("此功能可以打开游戏的截屏目录。"),
		_T("通常情况下，游戏的截屏储存于“snap”文件夹下。但在某些特殊情况下，由于权限等原因，游戏截屏可能并没有保存在该目录内。如果您遇到“在 snap 目录下没找到截屏”的情况，可以尝试使用此功能来查找截屏。"),
		OpenSnapFolder,
	},
	{
		1, FALSE, TRUE,
		NULL,
		_T("检查新版本"),
		_T("此功能可以联网检查本补丁的新版本。"),
		_T("将访问补丁网站并检查是否有新版本的补丁，如有新版补丁则会弹出提示，但仍需手动下载和安装。\r\n补丁网站：") PATCH_WEBSITE_BASE,
		CheckForUpdates,
	},
	{ -1 } // EOF
};



ConfigDescItem *ConfigDescList = ConfigDescList_CHS;
