// MouseCapView.h : interface of the CMouseCapView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSECAPVIEW_H__321F463F_379B_43E1_A6FE_577D7985E158__INCLUDED_)
#define AFX_MOUSECAPVIEW_H__321F463F_379B_43E1_A6FE_577D7985E158__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseCapView : public CView
{
protected:
	BOOL	m_bTracking;
	CPoint	m_ptFrom;
	CPoint	m_ptTo;

protected: // create from serialization only
	CMouseCapView();
	DECLARE_DYNCREATE(CMouseCapView)

// Attributes
public:
	CMouseCapDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseCapView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo);
	virtual ~CMouseCapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseCapView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MouseCapView.cpp
inline CMouseCapDoc* CMouseCapView::GetDocument()
   { return (CMouseCapDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSECAPVIEW_H__321F463F_379B_43E1_A6FE_577D7985E158__INCLUDED_)
