#pragma once



// CD2View ������ͼ

class CD2View : public CFormView
{
	DECLARE_DYNCREATE(CD2View)

protected:
	CD2View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
};


