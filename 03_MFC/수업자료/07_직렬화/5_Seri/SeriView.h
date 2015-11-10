// SeriView.h : interface of the CSeriView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIVIEW_H__E872595B_A457_4EBE_9E77_4D919A5ECFA4__INCLUDED_)
#define AFX_SERIVIEW_H__E872595B_A457_4EBE_9E77_4D919A5ECFA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSeriView : public CView
{
protected: // create from serialization only
	CSeriView();
	DECLARE_DYNCREATE(CSeriView)

// Attributes
public:
	CSeriDoc* GetDocument();

// Operations
public:
	COLORREF m_colorBrush;	//RGB(0,0,255);
	COLORREF m_colorPen;	//RGB(255,0,0);
	UINT m_nShape;		//IDM_RECTANGLE;
	CPoint m_ptOld;
	CPoint m_ptPre;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriView)
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
	void OnShape(UINT nID);
	void OnUpdateShape(CCmdUI *pCmdUI);
	virtual ~CSeriView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSeriView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUsePen();
	afx_msg void OnUseRectangle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SeriView.cpp
inline CSeriDoc* CSeriView::GetDocument()
   { return (CSeriDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIVIEW_H__E872595B_A457_4EBE_9E77_4D919A5ECFA4__INCLUDED_)
