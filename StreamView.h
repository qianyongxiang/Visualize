#pragma once
#include "afxwin.h"



// CStreamView 窗体视图

class CStreamView : public CFormView
{
	DECLARE_DYNCREATE(CStreamView)

protected:
	CStreamView();           // 动态创建所使用的受保护的构造函数
	virtual ~CStreamView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combox1;
	CComboBox m_combox2;
	CComboBox m_combox3;
	CString m_lon3;
	CString lat3;
	CString m_depth3;
public:
	afx_msg void OnBnClickedButton1();
private:
	CString m_streamdate;
public:
	afx_msg void OnPaint();
};


