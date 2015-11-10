// MSNButtonDemo.h : main header file for the MSNBUTTONDEMO application
//

#if !defined(AFX_MSNBUTTONDEMO_H__B76825F0_731E_442C_8FF3_7087301B9F1D__INCLUDED_)
#define AFX_MSNBUTTONDEMO_H__B76825F0_731E_442C_8FF3_7087301B9F1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMSNButtonDemoApp:
// See MSNButtonDemo.cpp for the implementation of this class
//

class CMSNButtonDemoApp : public CWinApp
{
public:
	CMSNButtonDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSNButtonDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMSNButtonDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSNBUTTONDEMO_H__B76825F0_731E_442C_8FF3_7087301B9F1D__INCLUDED_)
