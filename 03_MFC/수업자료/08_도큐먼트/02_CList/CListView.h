// CListView.h : interface of the CCListView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLISTVIEW_H__D14CA325_6D52_44EB_BE1B_F2E3C13B34D3__INCLUDED_)
#define AFX_CLISTVIEW_H__D14CA325_6D52_44EB_BE1B_F2E3C13B34D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCListView : public CView
{
protected: // create from serialization only
	CCListView();
	DECLARE_DYNCREATE(CCListView)

// Attributes
public:
	CCListDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCListView)
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
	virtual ~CCListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCListView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CListView.cpp
inline CCListDoc* CCListView::GetDocument()
   { return (CCListDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLISTVIEW_H__D14CA325_6D52_44EB_BE1B_F2E3C13B34D3__INCLUDED_)
