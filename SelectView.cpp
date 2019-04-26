// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "template_ocean.h"
#include "SelectView.h"
#include"MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//����ͼ�ĳ�ʼ��
	//��ȡ���ؼ�
	m_treeCtrl = &GetTreeCtrl();
	//1��׼��ͼƬ����
	HICON icon[6];
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	icon[4] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	icon[5] = AfxGetApp()->LoadIconW(IDI_ICON_DATE);
	m_imageList.Create(30, 30, ILC_COLOR32, 6, 6);
	for (int i = 0; i < 6; i++)
	{
		m_imageList.Add(icon[i]);
	}
	

	m_treeCtrl->SetImageList(&m_imageList,TVSIL_NORMAL);

	//2����ӽڵ�
	// TODO: �ڴ����ר�ô����/����û���
	HTREEITEM root1 = m_treeCtrl->InsertItem(TEXT("��ά����"), 0, 0, NULL);
	HTREEITEM segy = m_treeCtrl->InsertItem(TEXT("segy"), 1, 1, root1);
	HTREEITEM root2 = m_treeCtrl->InsertItem(TEXT("��ά����"), 0, 0, NULL);
	HTREEITEM tempera = m_treeCtrl->InsertItem(TEXT("�¶�"), 1, 1, root2);
	HTREEITEM salt = m_treeCtrl->InsertItem(TEXT("�ζ�"), 1, 1, root2);
	HTREEITEM u = m_treeCtrl->InsertItem(TEXT("����"), 1, 1, root2);


}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	CString str = m_treeCtrl->GetItemText(item);
	//MessageBox(str);
	if (str == TEXT("�¶�"))
	{
		//��Ҫ���������ͷ�ļ�#include"MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���봰�ڵ���Ϣ����
		//AfxGetMairWnd():��ܴ��ڶ���ָ��
		//AfxGetMairWnd()->GetSafeHwnd():��ȡ���ش��ڵľ��,CWnd::GetSafeHwnd
		//NM_A:�����Զ�����Ϣ
		//(WPARAM)NM_A:ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0��ָ���˸��ӵ���Ϣ��Ϣ���˲�������û������
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	if (str == TEXT("�ζ�"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���뵽���ڵ���Ϣ����
		//AfxGetMainWnd();	��ܴ��ڶ����ָ��
		//AfxGetMainWnd().GetSafeHwnd();��ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//WM_A	�Զ�����Ϣ
		//(WPARAM)WU_A	ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0		ָ���˸��ӵ���Ϣ��Ϣ���˲�������û�����塣
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	if (str == TEXT("����"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���뵽���ڵ���Ϣ����
		//AfxGetMainWnd();	��ܴ��ڶ����ָ��
		//AfxGetMainWnd().GetSafeHwnd();��ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//WM_A	�Զ�����Ϣ
		//(WPARAM)WU_A	ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0		ָ���˸��ӵ���Ϣ��Ϣ���˲�������û�����塣
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	if (str == TEXT("��ά����"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���뵽���ڵ���Ϣ����
		//AfxGetMainWnd();	��ܴ��ڶ����ָ��
		//AfxGetMainWnd().GetSafeHwnd();��ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//WM_A	�Զ�����Ϣ
		//(WPARAM)WU_A	ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0		ָ���˸��ӵ���Ϣ��Ϣ���˲�������û�����塣
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	if (str == TEXT("��ά����"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h"
		//CWnd::PostMessage ��һ����Ϣ���뵽���ڵ���Ϣ����
		//AfxGetMainWnd();	��ܴ��ڶ����ָ��
		//AfxGetMainWnd().GetSafeHwnd();��ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//WM_A	�Զ�����Ϣ
		//(WPARAM)WU_A	ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0		ָ���˸��ӵ���Ϣ��Ϣ���˲�������û�����塣
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
