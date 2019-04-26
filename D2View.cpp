// D2View.cpp : ʵ���ļ�
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


// CD2View ���

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


// CD2View ��Ϣ�������





void CD2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BACKGROUND);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.SetStretchBltMode(HALFTONE); //*����ڴ�
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}
