// CArrayView.h : interface of the CCArrayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARRAYVIEW_H__8FB330C5_6A6B_432A_B76E_0D082DE74FD5__INCLUDED_)
#define AFX_CARRAYVIEW_H__8FB330C5_6A6B_432A_B76E_0D082DE74FD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCArrayView : public CView
{
protected: // create from serialization only
	CCArrayView();
	DECLARE_DYNCREATE(CCArrayView)

// Attributes
public:
	CCArrayDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayView)
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
	virtual ~CCArrayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCArrayView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CArrayView.cpp
inline CCArrayDoc* CCArrayView::GetDocument()
   { return (CCArrayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAYVIEW_H__8FB330C5_6A6B_432A_B76E_0D082DE74FD5__INCLUDED_)
