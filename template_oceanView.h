
// template_oceanView.h : Ctemplate_oceanView ��Ľӿ�
//

#pragma once


class Ctemplate_oceanView : public CView
{
protected: // �������л�����
	Ctemplate_oceanView();
	DECLARE_DYNCREATE(Ctemplate_oceanView)

// ����
public:
	Ctemplate_oceanDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Ctemplate_oceanView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // template_oceanView.cpp �еĵ��԰汾
inline Ctemplate_oceanDoc* Ctemplate_oceanView::GetDocument() const
   { return reinterpret_cast<Ctemplate_oceanDoc*>(m_pDocument); }
#endif

