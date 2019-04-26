#pragma once
#include "afxwin.h"



// CSaltView 窗体视图

class CSaltView : public CFormView
{
	DECLARE_DYNCREATE(CSaltView)

protected:
	CSaltView();           // 动态创建所使用的受保护的构造函数
	virtual ~CSaltView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
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
	CString m_saltdate;
public:
	afx_msg void OnBnClickedButton1();
private:
	CString m_lon2;
	CString m_lat2;
	CString m_depth2;
public:
	afx_msg void OnPaint();
};


