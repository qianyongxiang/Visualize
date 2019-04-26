// StreamView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "template_ocean.h"
#include "StreamView.h"


// CStreamView

IMPLEMENT_DYNCREATE(CStreamView, CFormView)

CStreamView::CStreamView()
	: CFormView(IDD_DIALOG3)
	, m_lon3(_T(""))
	, lat3(_T(""))
	, m_depth3(_T(""))
	, m_streamdate(_T(""))
{

}

CStreamView::~CStreamView()
{
}

void CStreamView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_EDIT2, m_lon3);
	DDX_Text(pDX, IDC_EDIT3, lat3);
	DDX_Text(pDX, IDC_EDIT4, m_depth3);
	DDX_Text(pDX, IDC_EDIT1, m_streamdate);
}

BEGIN_MESSAGE_MAP(CStreamView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CStreamView::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CStreamView ���

#ifdef _DEBUG
void CStreamView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CStreamView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CStreamView ��Ϣ�������


void CStreamView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_lon3.IsEmpty() || lat3.IsEmpty() || m_depth3.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
}


void CStreamView::OnPaint()
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
