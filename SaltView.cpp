// SaltView.cpp : ʵ���ļ�
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


// CSaltView ���

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


// CSaltView ��Ϣ�������


void CSaltView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_lon2.IsEmpty() || m_lat2.IsEmpty() || m_depth2.IsEmpty())
	{
		MessageBox(TEXT("������Ϣ����"));
		return;
	}
	
}


void CSaltView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BACK1);
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.SetStretchBltMode(HALFTONE); //*����ڴ�
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}
