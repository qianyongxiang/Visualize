#pragma once



// CD2View 窗体视图

class CD2View : public CFormView
{
	DECLARE_DYNCREATE(CD2View)

protected:
	CD2View();           // 动态创建所使用的受保护的构造函数
	virtual ~CD2View();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
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

public:
	afx_msg void OnPaint();
};


