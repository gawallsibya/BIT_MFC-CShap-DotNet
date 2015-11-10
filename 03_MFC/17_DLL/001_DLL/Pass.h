// Pass.h : main header file for the PASS DLL
//

#if !defined(AFX_PASS_H__D4E47B8C_67F1_408E_BF82_7B1525BD20ED__INCLUDED_)
#define AFX_PASS_H__D4E47B8C_67F1_408E_BF82_7B1525BD20ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPassApp
// See Pass.cpp for the implementation of this class
//

class CPassApp : public CWinApp
{
public:
	CPassApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPassApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASS_H__D4E47B8C_67F1_408E_BF82_7B1525BD20ED__INCLUDED_)
