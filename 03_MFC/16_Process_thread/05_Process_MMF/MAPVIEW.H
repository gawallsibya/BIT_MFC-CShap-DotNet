// MapView.h : interface of the CMapView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPVIEW_H__12CA386D_545D_11D2_A843_00A02486730F__INCLUDED_)
#define AFX_MAPVIEW_H__12CA386D_545D_11D2_A843_00A02486730F__INCLUDED_

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

class CMapView : public CView
{
protected: // create from serialization only
	CMapView();
	DECLARE_DYNCREATE(CMapView)

// Attributes
public:
	CMapDoc* GetDocument();

// Operations
public:
	HANDLE  m_Map;
	CData*  m_ViewData;
	CPoint   m_start;
	COLORREF m_color;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMapView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MapView.cpp
inline CMapDoc* CMapView::GetDocument()
   { return (CMapDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPVIEW_H__12CA386D_545D_11D2_A843_00A02486730F__INCLUDED_)
