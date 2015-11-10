// Pass.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Pass.h"

#include "SetupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CPassApp

BEGIN_MESSAGE_MAP(CPassApp, CWinApp)
	//{{AFX_MSG_MAP(CPassApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassApp construction

CPassApp::CPassApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPassApp object

CPassApp theApp;

// 익스포트 함수 정의 
#ifdef __cplusplus
	extern "C" {
#endif 
		
	__declspec(dllexport) BOOL ShowSetupDialog(char* szMail, char* szPath)
	{
		CSetupDlg  dlg;
		dlg.m_Path = szPath;
		if(dlg.DoModal() == IDOK)
		{
			lstrcpy(szMail, dlg.m_Mail);
			lstrcpy(szPath, dlg.m_Path);
			return TRUE;
		}
		return FALSE;
	}

#ifdef __cplusplus
	}
#endif 