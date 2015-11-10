#if !defined(AFX_HTSTATIC_H__7094634A_EAF8_42F0_9C1E_F45B6B3F384C__INCLUDED_)
#define AFX_HTSTATIC_H__7094634A_EAF8_42F0_9C1E_F45B6B3F384C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HTStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHTStatic window

class CHTStatic : public CStatic
{
// Construction
public:
	CHTStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTStatic)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL		m_bMouseOn;
	HBRUSH		m_hBrush;
	HCURSOR		m_hCursor;
	virtual ~CHTStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHTStatic)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTSTATIC_H__7094634A_EAF8_42F0_9C1E_F45B6B3F384C__INCLUDED_)
