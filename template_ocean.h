
// template_ocean.h : template_ocean Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ctemplate_oceanApp:
// �йش����ʵ�֣������ template_ocean.cpp
//

class Ctemplate_oceanApp : public CWinAppEx
{
public:
	Ctemplate_oceanApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctemplate_oceanApp theApp;
