// SampleView.h : interface of the CSampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLEVIEW_H__931A353F_EA0F_4538_8EB6_8ACDACB07301__INCLUDED_)
#define AFX_SAMPLEVIEW_H__931A353F_EA0F_4538_8EB6_8ACDACB07301__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSampleView : public CView
{
protected: // create from serialization only
	CSampleView();
	DECLARE_DYNCREATE(CSampleView)

// Attributes
public:
	CSampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSampleView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SampleView.cpp
inline CSampleDoc* CSampleView::GetDocument()
   { return (CSampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEVIEW_H__931A353F_EA0F_4538_8EB6_8ACDACB07301__INCLUDED_)
