// Serialize.h : main header file for the SERIALIZE application
//

#if !defined(AFX_SERIALIZE_H__217C1D0F_1AFC_4413_AA7C_A3E9C3691CE8__INCLUDED_)
#define AFX_SERIALIZE_H__217C1D0F_1AFC_4413_AA7C_A3E9C3691CE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerializeApp:
// See Serialize.cpp for the implementation of this class
//

class CSerializeApp : public CWinApp
{
public:
	CSerializeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CSerializeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALIZE_H__217C1D0F_1AFC_4413_AA7C_A3E9C3691CE8__INCLUDED_)
