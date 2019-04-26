
// template_oceanView.cpp : Ctemplate_oceanView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "template_ocean.h"
#endif

#include "template_oceanDoc.h"
#include "template_oceanView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctemplate_oceanView

IMPLEMENT_DYNCREATE(Ctemplate_oceanView, CView)

BEGIN_MESSAGE_MAP(Ctemplate_oceanView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ctemplate_oceanView 构造/析构

Ctemplate_oceanView::Ctemplate_oceanView()
{
	// TODO: 在此处添加构造代码

}

Ctemplate_oceanView::~Ctemplate_oceanView()
{
}

BOOL Ctemplate_oceanView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctemplate_oceanView 绘制

void Ctemplate_oceanView::OnDraw(CDC* /*pDC*/)
{
	Ctemplate_oceanDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctemplate_oceanView 打印

BOOL Ctemplate_oceanView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctemplate_oceanView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctemplate_oceanView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Ctemplate_oceanView 诊断

#ifdef _DEBUG
void Ctemplate_oceanView::AssertValid() const
{
	CView::AssertValid();
}

void Ctemplate_oceanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctemplate_oceanDoc* Ctemplate_oceanView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctemplate_oceanDoc)));
	return (Ctemplate_oceanDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctemplate_oceanView 消息处理程序
