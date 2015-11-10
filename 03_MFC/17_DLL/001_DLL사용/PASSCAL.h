// PASSCAL.h : main header file for the PASSCAL application
//

#if !defined(AFX_PASSCAL_H__80EAC4AC_192A_48A6_BE05_8BE48898332B__INCLUDED_)
#define AFX_PASSCAL_H__80EAC4AC_192A_48A6_BE05_8BE48898332B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPASSCALApp:
// See PASSCAL.cpp for the implementation of this class
//

class CPASSCALApp : public CWinApp
{
public:
	CPASSCALApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPASSCALApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPASSCALApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSCAL_H__80EAC4AC_192A_48A6_BE05_8BE48898332B__INCLUDED_)
