#if !defined(AFX_PANEVIEW_H__B19766CE_2DA1_4D30_AD21_DAEC27F8F4F7__INCLUDED_)
#define AFX_PANEVIEW_H__B19766CE_2DA1_4D30_AD21_DAEC27F8F4F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaneView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaneView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CPaneView : public CFormView
{
protected:
	CPaneView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPaneView)

// Form Data
public:
	//{{AFX_DATA(CPaneView)
	enum { IDD = IDD_FORMVIEW };
	CString	m_str;
	int		m_color;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaneView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPaneView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPaneView)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANEVIEW_H__B19766CE_2DA1_4D30_AD21_DAEC27F8F4F7__INCLUDED_)
