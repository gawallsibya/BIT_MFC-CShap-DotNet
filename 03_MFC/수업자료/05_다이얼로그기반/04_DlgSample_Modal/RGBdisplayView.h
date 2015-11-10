// RGBdisplayView.h : interface of the CRGBdisplayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGBDISPLAYVIEW_H__AA364DCA_7598_4FB4_874F_125DB0E68088__INCLUDED_)
#define AFX_RGBDISPLAYVIEW_H__AA364DCA_7598_4FB4_874F_125DB0E68088__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRGBdisplayView : public CView
{
protected: // create from serialization only
	CRGBdisplayView();
	DECLARE_DYNCREATE(CRGBdisplayView)

// Attributes
public:
	CRGBdisplayDoc* GetDocument();

// Operations
public:
	CString str;
	COLORREF fcolor, bcolor;
	int r, g, b;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGBdisplayView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRGBdisplayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRGBdisplayView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFontcolor();
	afx_msg void OnBackcolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RGBdisplayView.cpp
inline CRGBdisplayDoc* CRGBdisplayView::GetDocument()
   { return (CRGBdisplayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGBDISPLAYVIEW_H__AA364DCA_7598_4FB4_874F_125DB0E68088__INCLUDED_)
