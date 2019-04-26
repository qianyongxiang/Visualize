// D2View.cpp : 实现文件
//

#include "stdafx.h"
#include "template_ocean.h"
#include "D2View.h"


// CD2View

IMPLEMENT_DYNCREATE(CD2View, CFormView)

CD2View::CD2View()
	: CFormView(IDD_DIALOG4)
{

}

CD2View::~CD2View()
{
}

void CD2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CD2View, CFormView)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CD2View 诊断

#ifdef _DEBUG
void CD2View::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CD2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CD2View 消息处理程序





void CD2View::OnPaint()
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
