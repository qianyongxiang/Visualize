#pragma once
#include "afxwin.h"



// CTempView 窗体视图

class CTempView : public CFormView
{
	DECLARE_DYNCREATE(CTempView)

protected:
	CTempView();           // 动态创建所使用的受保护的构造函数
	virtual ~CTempView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
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
	CString m_tempdate;
public:
	afx_msg void OnEnChangeEdit1();
	/*virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
*/
private:
	CString m_lon1;
	CString m_lat1;
	CString m_depth;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};

