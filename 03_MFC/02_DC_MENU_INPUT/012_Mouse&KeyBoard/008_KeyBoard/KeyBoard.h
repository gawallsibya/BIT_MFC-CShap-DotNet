// KeyBoard.h : main header file for the KEYBOARD application
//

#if !defined(AFX_KEYBOARD_H__C44C83A2_0F71_401B_9B4C_914F023D3351__INCLUDED_)
#define AFX_KEYBOARD_H__C44C83A2_0F71_401B_9B4C_914F023D3351__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyBoardApp:
// See KeyBoard.cpp for the implementation of this class
//

class CKeyBoardApp : public CWinApp
{
public:
	CKeyBoardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyBoardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CKeyBoardApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYBOARD_H__C44C83A2_0F71_401B_9B4C_914F023D3351__INCLUDED_)
