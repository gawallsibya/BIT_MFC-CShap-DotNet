#if !defined(AFX_MYSPLITTERWND_H__7AD53E20_BBBB_40BA_8363_03FDC96A5B9E__INCLUDED_)
#define AFX_MYSPLITTERWND_H__7AD53E20_BBBB_40BA_8363_03FDC96A5B9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMySplitterWnd frame with splitter

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMySplitterWnd : public CSplitterWnd
{
	DECLARE_DYNCREATE(CMySplitterWnd)
protected:

// Attributes

// Operations
public:
	CMySplitterWnd();           // protected constructor used by dynamic creation

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySplitterWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySplitterWnd();

	// Generated message map functions
	//{{AFX_MSG(CMySplitterWnd)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSPLITTERWND_H__7AD53E20_BBBB_40BA_8363_03FDC96A5B9E__INCLUDED_)
