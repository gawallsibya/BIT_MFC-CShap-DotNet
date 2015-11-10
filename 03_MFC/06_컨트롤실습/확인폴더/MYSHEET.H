// MySheet.h : header file
//
// This class defines custom modal property sheet 
// CMySheet.
 
#ifndef __MYSHEET_H__
#define __MYSHEET_H__

#include "Page.h"

/////////////////////////////////////////////////////////////////////////////
// CMySheet

class CMySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMySheet)

// Construction
public:
	CMySheet(CWnd* pWndParent = NULL);

// Attributes
public:
	CMyPage1 m_Page1;
	CMyPage2 m_Page2;
	CMyPage3 m_Page3;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CMySheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __MYSHEET_H__
