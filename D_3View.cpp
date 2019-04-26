// D_3View.cpp : ʵ���ļ�
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


// CD_3View ���

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


// CD_3View ��Ϣ�������


void CD_3View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
}


void CD_3View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CD_3View::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}





void CD_3View::OnPaint()
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
