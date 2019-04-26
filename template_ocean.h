
// template_ocean.h : template_ocean 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Ctemplate_oceanApp:
// 有关此类的实现，请参阅 template_ocean.cpp
//

class Ctemplate_oceanApp : public CWinAppEx
{
public:
	Ctemplate_oceanApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctemplate_oceanApp theApp;
