
// MainFrm.cpp : CMainFrame ���ʵ��
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

	//ON_MESSAGE ��Ӧ�����Զ�����Ϣ
	//����NM_X��Ϣ���Զ�����OnMyChange����
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_SYSU));
	SetTitle(TEXT("������ʾ"));
	MoveWindow(0, 0, 800, 500);
	CenterWindow();

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	// TODO: �ڴ����ר�ô����/����û���
	//��̬��ִ��ڣ�1��2�У�CSplitterWnd:CreatStatic
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
		//MessageBox(TEXT("�¶Ƚ�����أ�"));
		//���ؽ���
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
		//MessageBox(TEXT("�ζȽ������"));
		//���ؽ���
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
		//MessageBox(TEXT("���ٽ������"));
		//���ؽ���
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
		//MessageBox(TEXT("��ά�������"));
		//���ؽ���
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
		//MessageBox(TEXT("��ά�������"));
		//���ؽ���
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
