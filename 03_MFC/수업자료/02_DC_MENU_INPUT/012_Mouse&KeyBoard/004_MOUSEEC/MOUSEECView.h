// MOUSEECView.h : interface of the CMOUSEECView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSEECVIEW_H__59C123EC_0786_47E8_A1AD_091B9298F04A__INCLUDED_)
#define AFX_MOUSEECVIEW_H__59C123EC_0786_47E8_A1AD_091B9298F04A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMOUSEECView : public CView
{
public:
	BOOL	m_bMouseOver;
protected: // create from serialization only
	CMOUSEECView();
	DECLARE_DYNCREATE(CMOUSEECView)

// Attributes
public:
	CMOUSEECDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMOUSEECView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	virtual ~CMOUSEECView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMOUSEECView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MOUSEECView.cpp
inline CMOUSEECDoc* CMOUSEECView::GetDocument()
   { return (CMOUSEECDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEECVIEW_H__59C123EC_0786_47E8_A1AD_091B9298F04A__INCLUDED_)
