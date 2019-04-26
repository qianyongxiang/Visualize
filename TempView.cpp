// TempView.cpp : ʵ���ļ�
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


// CTempView ���

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


// CTempView ��Ϣ�������


void CTempView::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


//void CTempView::OnInitialUpdate()
//{
//	CFormView::OnInitialUpdate();
//	CInfoFile file;
//	float lon, lat, deep, temp;
//	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
//	{
//		//������Ʒ����  ���������Ʒŵ���������
//
//		//it -> name�� String  AddString(CString)
//		//string -> CString
//		m_combox1.AddString((CString)it->lon);
//		//if ((CString)it->name.c_str() == name)
//		//{
//		//	n_price = it->price;
//		//	m_left = it->num;
//		//	//ͬ�����ؼ���
//		//	UpdateData(FALSE);
//		//}
//	}
//	//Ĭ��ѡ�е�һ����Ʒ
//	m_combox1.SetCurSel(0);
//	OnCbnSelchangeCombo1();
//	// TODO: �ڴ����ר�ô����/����û���
//}
//
//
//void CTempView::OnCbnSelchangeCombo1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	//�л�
//	int index = m_combox1.GetCurSel();
//	float lon;
//	m_combox1.GetLBText(index, lon);
//}


void CTempView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_lon1.IsEmpty() || m_lat1.IsEmpty() || m_depth.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
}


void CTempView::OnPaint()
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
