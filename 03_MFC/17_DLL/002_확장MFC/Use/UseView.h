// UseView.h : interface of the CUseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEVIEW_H__1599868B_D77D_4644_8949_B6E6CE3CD44D__INCLUDED_)
#define AFX_USEVIEW_H__1599868B_D77D_4644_8949_B6E6CE3CD44D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// MFC 확장 DLL사용하기.
#include "NumEdit.h" // 1. 헤더 include

#pragma comment(lib, "MFCEX.lib")//2. linker에게 lib를 알려준다.
//							// 외우세요..
class CUseView : public CView
{
protected: // create from serialization only
	CUseView();
	DECLARE_DYNCREATE(CUseView)

// Attributes
public:
	CNumEdit m_edit;

	CUseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseView.cpp
inline CUseDoc* CUseView::GetDocument()
   { return (CUseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEVIEW_H__1599868B_D77D_4644_8949_B6E6CE3CD44D__INCLUDED_)
