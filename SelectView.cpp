// SelectView.cpp : 实现文件
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


// CSelectView 诊断

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


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//树视图的初始化
	//获取树控件
	m_treeCtrl = &GetTreeCtrl();
	//1、准备图片集合
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

	//2、添加节点
	// TODO: 在此添加专用代码和/或调用基类
	HTREEITEM root1 = m_treeCtrl->InsertItem(TEXT("二维数据"), 0, 0, NULL);
	HTREEITEM segy = m_treeCtrl->InsertItem(TEXT("segy"), 1, 1, root1);
	HTREEITEM root2 = m_treeCtrl->InsertItem(TEXT("三维数据"), 0, 0, NULL);
	HTREEITEM tempera = m_treeCtrl->InsertItem(TEXT("温度"), 1, 1, root2);
	HTREEITEM salt = m_treeCtrl->InsertItem(TEXT("盐度"), 1, 1, root2);
	HTREEITEM u = m_treeCtrl->InsertItem(TEXT("流速"), 1, 1, root2);


}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	CString str = m_treeCtrl->GetItemText(item);
	//MessageBox(str);
	if (str == TEXT("温度"))
	{
		//需要包含框架类头文件#include"MainFrm.h"
		//CWnd::PostMessage 将一个消息放入窗口的消息队列
		//AfxGetMairWnd():框架窗口对象指针
		//AfxGetMairWnd()->GetSafeHwnd():获取返回窗口的句柄,CWnd::GetSafeHwnd
		//NM_A:发送自定义消息
		//(WPARAM)NM_A:指定了附加的消息信息
		//(LPARAM)0：指定了附加的消息信息，此参数这里没有意义
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	if (str == TEXT("盐度"))
	{
		//需要包含框架类头文件#include "MainFrm.h"
		//CWnd::PostMessage 将一个消息放入到窗口的消息队列
		//AfxGetMainWnd();	框架窗口对象的指针
		//AfxGetMainWnd().GetSafeHwnd();获取返回窗口的句柄，CWnd::GetSafeHwnd
		//WM_A	自定义消息
		//(WPARAM)WU_A	指定了附加的消息信息
		//(LPARAM)0		指定了附加的消息信息，此参数这里没有意义。
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	if (str == TEXT("流速"))
	{
		//需要包含框架类头文件#include "MainFrm.h"
		//CWnd::PostMessage 将一个消息放入到窗口的消息队列
		//AfxGetMainWnd();	框架窗口对象的指针
		//AfxGetMainWnd().GetSafeHwnd();获取返回窗口的句柄，CWnd::GetSafeHwnd
		//WM_A	自定义消息
		//(WPARAM)WU_A	指定了附加的消息信息
		//(LPARAM)0		指定了附加的消息信息，此参数这里没有意义。
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	if (str == TEXT("二维数据"))
	{
		//需要包含框架类头文件#include "MainFrm.h"
		//CWnd::PostMessage 将一个消息放入到窗口的消息队列
		//AfxGetMainWnd();	框架窗口对象的指针
		//AfxGetMainWnd().GetSafeHwnd();获取返回窗口的句柄，CWnd::GetSafeHwnd
		//WM_A	自定义消息
		//(WPARAM)WU_A	指定了附加的消息信息
		//(LPARAM)0		指定了附加的消息信息，此参数这里没有意义。
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	if (str == TEXT("三维数据"))
	{
		//需要包含框架类头文件#include "MainFrm.h"
		//CWnd::PostMessage 将一个消息放入到窗口的消息队列
		//AfxGetMainWnd();	框架窗口对象的指针
		//AfxGetMainWnd().GetSafeHwnd();获取返回窗口的句柄，CWnd::GetSafeHwnd
		//WM_A	自定义消息
		//(WPARAM)WU_A	指定了附加的消息信息
		//(LPARAM)0		指定了附加的消息信息，此参数这里没有意义。
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
