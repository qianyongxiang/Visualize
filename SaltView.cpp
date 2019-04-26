// SaltView.cpp : 实现文件
//

#include "stdafx.h"
#include "template_ocean.h"
#include "SaltView.h"


// CSaltView

IMPLEMENT_DYNCREATE(CSaltView, CFormView)

CSaltView::CSaltView()
	: CFormView(IDD_DIALOG2)
	, m_saltdate(_T(""))
	, m_lon2(_T(""))
	, m_lat2(_T(""))
	, m_depth2(_T(""))
{

}

CSaltView::~CSaltView()
{
}

void CSaltView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_EDIT1, m_saltdate);
	DDX_Text(pDX, IDC_EDIT2, m_lon2);
	DDX_Text(pDX, IDC_EDIT3, m_lat2);
	DDX_Text(pDX, IDC_EDIT4, m_depth2);
}

BEGIN_MESSAGE_MAP(CSaltView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSaltView::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSaltView 诊断

#ifdef _DEBUG
void CSaltView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSaltView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSaltView 消息处理程序


void CSaltView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_lon2.IsEmpty() || m_lat2.IsEmpty() || m_depth2.IsEmpty())
	{
		MessageBox(TEXT("输入信息有误"));
		return;
	}
	
}


void CSaltView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFormView::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BACK1);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.SetStretchBltMode(HALFTONE); //*添加于此
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}
