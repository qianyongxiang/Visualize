#pragma once



// CD_3View ������ͼ

class CD_3View : public CFormView
{
	DECLARE_DYNCREATE(CD_3View)

protected:
	CD_3View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CD_3View();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	/*virtual void OnInitialUpdate();*/
	afx_msg void OnPaint();
};


