// aaaView.h : interface of the CAaaView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AAAVIEW_H__B22AFD8E_978D_44C6_92E9_9ABDFBE2DD2E__INCLUDED_)
#define AFX_AAAVIEW_H__B22AFD8E_978D_44C6_92E9_9ABDFBE2DD2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAaaView : public CView
{
protected: // create from serialization only
	CAaaView();
	DECLARE_DYNCREATE(CAaaView)

// Attributes
public:
	CAaaDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaView)
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
	virtual ~CAaaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAaaView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in aaaView.cpp
inline CAaaDoc* CAaaView::GetDocument()
   { return (CAaaDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAAVIEW_H__B22AFD8E_978D_44C6_92E9_9ABDFBE2DD2E__INCLUDED_)
