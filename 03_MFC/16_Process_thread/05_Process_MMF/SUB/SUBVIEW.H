// SubView.h : interface of the CSubView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUBVIEW_H__12CA3881_545D_11D2_A843_00A02486730F__INCLUDED_)
#define AFX_SUBVIEW_H__12CA3881_545D_11D2_A843_00A02486730F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define DRAW_READY 1
#define DRAW_START 777
#define DRAW_STOP -1

struct CData
{
	UINT     flag;
	COLORREF color;
	CPoint   start;
	CPoint   pt;
};

class CSubView : public CView
{
protected: // create from serialization only
	CSubView();
	DECLARE_DYNCREATE(CSubView)

// Attributes
public:
	CSubDoc* GetDocument();

// Operations
public:
	HANDLE  m_Map;
	CData*  m_ViewData;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	static UINT SpyInfo(LPVOID lParam);
	virtual ~CSubView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSubView)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SubView.cpp
inline CSubDoc* CSubView::GetDocument()
   { return (CSubDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBVIEW_H__12CA3881_545D_11D2_A843_00A02486730F__INCLUDED_)
