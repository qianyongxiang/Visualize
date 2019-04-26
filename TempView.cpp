// TempView.cpp : 实现文件
//

#include "stdafx.h"
#include "template_ocean.h"
#include "TempView.h"
#include"InfoFile.h"


// CTempView

IMPLEMENT_DYNCREATE(CTempView, CFormView)

CTempView::CTempView()
	: CFormView(IDD_DIALOG1)
	, m_tempdate(_T(""))
	, m_lon1(_T(""))
	, m_lat1(_T(""))
	, m_depth(_T(""))
{

}

CTempView::~CTempView()
{
}

void CTempView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_EDIT1, m_tempdate);
	DDX_Text(pDX, IDC_EDIT2, m_lon1);
	DDX_Text(pDX, IDC_EDIT3, m_lat1);
	DDX_Text(pDX, IDC_EDIT4, m_depth);
}

BEGIN_MESSAGE_MAP(CTempView, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CTempView::OnEnChangeEdit1)
	/*ON_CBN_SELCHANGE(IDC_COMBO1, &CTempView::OnCbnSelchangeCombo1)*/
	ON_BN_CLICKED(IDC_BUTTON1, &CTempView::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTempView 诊断

#ifdef _DEBUG
void CTempView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CTempView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTempView 消息处理程序


void CTempView::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


//void CTempView::OnInitialUpdate()
//{
//	CFormView::OnInitialUpdate();
//	CInfoFile file;
//	float lon, lat, deep, temp;
//	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
//	{
//		//遍历商品名称  把容器名称放到下拉框中
//
//		//it -> name是 String  AddString(CString)
//		//string -> CString
//		m_combox1.AddString((CString)it->lon);
//		//if ((CString)it->name.c_str() == name)
//		//{
//		//	n_price = it->price;
//		//	m_left = it->num;
//		//	//同步到控件上
//		//	UpdateData(FALSE);
//		//}
//	}
//	//默认选中第一个商品
//	m_combox1.SetCurSel(0);
//	OnCbnSelchangeCombo1();
//	// TODO: 在此添加专用代码和/或调用基类
//}
//
//
//void CTempView::OnCbnSelchangeCombo1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	//切换
//	int index = m_combox1.GetCurSel();
//	float lon;
//	m_combox1.GetLBText(index, lon);
//}


void CTempView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_lon1.IsEmpty() || m_lat1.IsEmpty() || m_depth.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
}


void CTempView::OnPaint()
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
