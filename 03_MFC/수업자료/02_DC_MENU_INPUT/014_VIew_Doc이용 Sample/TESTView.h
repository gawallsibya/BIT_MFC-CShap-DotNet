// TESTView.h : interface of the CTESTView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__3C498D46_062B_4D79_B539_22041059E01A__INCLUDED_)
#define AFX_TESTVIEW_H__3C498D46_062B_4D79_B539_22041059E01A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTESTView : public CView
{
protected: // create from serialization only
	CTESTView();
	DECLARE_DYNCREATE(CTESTView)

// Attributes
public:
	CTESTDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTESTView)
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
	void DrawRectangle(CPoint pt);
	virtual ~CTESTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTESTView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TESTView.cpp
inline CTESTDoc* CTESTView::GetDocument()
   { return (CTESTDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__3C498D46_062B_4D79_B539_22041059E01A__INCLUDED_)
