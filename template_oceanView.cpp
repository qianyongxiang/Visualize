
// template_oceanView.cpp : Ctemplate_oceanView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ctemplate_oceanView ����/����

Ctemplate_oceanView::Ctemplate_oceanView()
{
	// TODO: �ڴ˴���ӹ������

}

Ctemplate_oceanView::~Ctemplate_oceanView()
{
}

BOOL Ctemplate_oceanView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctemplate_oceanView ����

void Ctemplate_oceanView::OnDraw(CDC* /*pDC*/)
{
	Ctemplate_oceanDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctemplate_oceanView ��ӡ

BOOL Ctemplate_oceanView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ctemplate_oceanView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ctemplate_oceanView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Ctemplate_oceanView ���

#ifdef _DEBUG
void Ctemplate_oceanView::AssertValid() const
{
	CView::AssertValid();
}

void Ctemplate_oceanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctemplate_oceanDoc* Ctemplate_oceanView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctemplate_oceanDoc)));
	return (Ctemplate_oceanDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctemplate_oceanView ��Ϣ�������
