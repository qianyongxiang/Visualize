
// template_oceanView.h : Ctemplate_oceanView 类的接口
//

#pragma once


class Ctemplate_oceanView : public CView
{
protected: // 仅从序列化创建
	Ctemplate_oceanView();
	DECLARE_DYNCREATE(Ctemplate_oceanView)

// 特性
public:
	Ctemplate_oceanDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Ctemplate_oceanView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // template_oceanView.cpp 中的调试版本
inline Ctemplate_oceanDoc* Ctemplate_oceanView::GetDocument() const
   { return reinterpret_cast<Ctemplate_oceanDoc*>(m_pDocument); }
#endif

