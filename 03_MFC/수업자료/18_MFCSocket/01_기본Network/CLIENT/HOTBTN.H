// MyButton.h : header file
//
#ifndef __HOTBUTTON_H__
#define __HOTBUTTON_H__

#include "resource.h"

class CHotButton : public CButton
{
// Construction
public:
	CHotButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetIcon(UINT nID, int nWidth = 32, int nHeight = 32);
	void BtnTextColor(COLORREF color);
	void SetButtonBorder(BOOL border = TRUE);
	virtual ~CHotButton();

	// Generated message map functions
protected:
	CSize m_szIcon;
	HICON m_hIcon;
	BOOL    m_onsurface;
    BOOL    m_down;
	BOOL    m_border;
	COLORREF m_txtColor;
    virtual void DrawItem(LPDRAWITEMSTRUCT pDraw);
    //{{AFX_MSG(CHotButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif //__HOTBUTTON_H__
