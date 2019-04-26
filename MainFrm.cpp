
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "template_ocean.h"
#include"SelectView.h"
#include"DisplayView.h"
#include"TempView.h"
#include"SaltView.h"
#include"StreamView.h"
#include"D2View.h"
#include"D_3View.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	//ON_MESSAGE 响应的是自定义消息
	//产生NM_X消息，自动调用OnMyChange函数
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_SYSU));
	SetTitle(TEXT("数据显示"));
	MoveWindow(0, 0, 800, 500);
	CenterWindow();

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	// TODO: 在此添加专用代码和/或调用基类
	//静态拆分窗口，1行2列，CSplitterWnd:CreatStatic
	m_spliter.CreateStatic(this, 1, 2);
	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);
	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);


	return TRUE;
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{

	CCreateContext context;
	if (wParam == NM_A)
	{
		//MessageBox(TEXT("温度界面挂载！"));
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CTempView);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CTempView), CSize(600, 500), &context);
		CTempView *pNewView = (CTempView*)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_B)
	{
		//MessageBox(TEXT("盐度界面挂载"));
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CSaltView);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CSaltView), CSize(600, 500), &context);
		CSaltView *pNewView = (CSaltView*)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_C)
	{
		//MessageBox(TEXT("流速界面挂载"));
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CStreamView);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CStreamView), CSize(600, 500), &context);
		CStreamView *pNewView = (CStreamView*)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_D)
	{
		//MessageBox(TEXT("二维界面挂载"));
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CD2View);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CD2View), CSize(600, 500), &context);
		CD2View *pNewView = (CD2View*)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_E)
	{
		//MessageBox(TEXT("三维界面挂载"));
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CD_3View);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CD_3View), CSize(600, 500), &context);
		CD_3View *pNewView = (CD_3View*)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	return 0;
}
