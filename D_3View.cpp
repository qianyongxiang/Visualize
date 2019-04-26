// D_3View.cpp : 实现文件
//

#include "stdafx.h"
#include "template_ocean.h"
#include "D_3View.h"
#include "SelectView.h"
#include "MainFrm.h"


// CD_3View

IMPLEMENT_DYNCREATE(CD_3View, CFormView)

CD_3View::CD_3View()
	: CFormView(IDD_DIALOG5)
{

}

CD_3View::~CD_3View()
{
}

void CD_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CD_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CD_3View::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_BUTTON3, &CD_3View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CD_3View::OnBnClickedButton4)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CD_3View 诊断

#ifdef _DEBUG
void CD_3View::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CD_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CD_3View 消息处理程序


void CD_3View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
}


void CD_3View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CD_3View::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}





void CD_3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFormView::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BACKGROUND);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.SetStretchBltMode(HALFTONE); //*添加于此
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}
