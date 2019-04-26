// StreamView.cpp : 实现文件
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


// CStreamView 诊断

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


// CStreamView 消息处理程序


void CStreamView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_lon3.IsEmpty() || lat3.IsEmpty() || m_depth3.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
}


void CStreamView::OnPaint()
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
