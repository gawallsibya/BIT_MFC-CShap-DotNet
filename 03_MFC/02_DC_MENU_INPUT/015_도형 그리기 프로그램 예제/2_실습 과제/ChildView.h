// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__454C98E3_1AB4_406E_8E13_4B2340C091CB__INCLUDED_)
#define AFX_CHILDVIEW_H__454C98E3_1AB4_406E_8E13_4B2340C091CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

#include <afxtempl.h>

//#include "Widget.h"
class CWidget; // include ���ʿ� ���� ���漱�� ���ָ� �ȴ�.
               // ������ ������� �ʴ´�.

class CChildView : public CWnd
{
	CList<CWidget*, CWidget*> wList; // ������ ���� ���� ����Ʈ

// Construction
public:
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__454C98E3_1AB4_406E_8E13_4B2340C091CB__INCLUDED_)
