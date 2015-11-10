// 상태바2.h : main header file for the 상태바2 application
//

#if !defined(AFX_2_H__6E1780ED_FFC0_48BB_9049_58F8B933A76F__INCLUDED_)
#define AFX_2_H__6E1780ED_FFC0_48BB_9049_58F8B933A76F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy2App:
// See 상태바2.cpp for the implementation of this class
//

class CMy2App : public CWinApp
{
public:
	CMy2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMy2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2_H__6E1780ED_FFC0_48BB_9049_58F8B933A76F__INCLUDED_)
