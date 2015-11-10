// MDIHelloView.h : interface of the CMDIHelloView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIHELLOVIEW_H__C4E0BDFF_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
#define AFX_MDIHELLOVIEW_H__C4E0BDFF_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDIHelloView : public CView
{
protected: // create from serialization only
	CMDIHelloView();
	DECLARE_DYNCREATE(CMDIHelloView)

// Attributes
public:
	CMDIHelloDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIHelloView)
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
	virtual ~CMDIHelloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIHelloView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDIHelloView.cpp
inline CMDIHelloDoc* CMDIHelloView::GetDocument()
   { return (CMDIHelloDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHELLOVIEW_H__C4E0BDFF_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
