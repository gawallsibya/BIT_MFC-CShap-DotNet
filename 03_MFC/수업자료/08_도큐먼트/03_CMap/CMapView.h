// CMapView.h : interface of the CCMapView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMAPVIEW_H__210C696C_6434_4596_B956_174C7F1F9E4B__INCLUDED_)
#define AFX_CMAPVIEW_H__210C696C_6434_4596_B956_174C7F1F9E4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCMapView : public CView
{
protected: // create from serialization only
	CCMapView();
	DECLARE_DYNCREATE(CCMapView)

// Attributes
public:
	CCMapDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMapView)
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
	virtual ~CCMapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCMapView)
	afx_msg void OnMcmap();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CMapView.cpp
inline CCMapDoc* CCMapView::GetDocument()
   { return (CCMapDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMAPVIEW_H__210C696C_6434_4596_B956_174C7F1F9E4B__INCLUDED_)
