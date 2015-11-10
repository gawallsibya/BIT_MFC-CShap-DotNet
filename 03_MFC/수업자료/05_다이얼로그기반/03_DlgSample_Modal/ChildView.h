// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__2E215365_CF2E_46A2_B907_D4ABFFF8EACC__INCLUDED_)
#define AFX_CHILDVIEW_H__2E215365_CF2E_46A2_B907_D4ABFFF8EACC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	UINT	 m_color;
	CSize	 m_size;

	COLORREF m_useColor;

	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnColorRed();
	afx_msg void OnColorBlue();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlack();
	afx_msg void OnSizeBig();
	afx_msg void OnSizeNormal();
	afx_msg void OnSizeSmall();
	afx_msg void OnColorSetting();
	afx_msg void OnColorOther();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__2E215365_CF2E_46A2_B907_D4ABFFF8EACC__INCLUDED_)
