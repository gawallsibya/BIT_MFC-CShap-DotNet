// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__92861564_1D56_481F_BF1F_2437C2CDA5A5__INCLUDED_)
#define AFX_STDAFX_H__92861564_1D56_481F_BF1F_2437C2CDA5A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//크리티컬 섹션을 사용하기 위해서 추가된 헤더
#include <afxmt.h>
//크리티컬 섹션
extern CCriticalSection	g_CS;
extern char* g_pszBuffer;

void SetString(char* pszData);
BOOL GetString(char* pszData);

UINT ThreadFunc1(LPVOID pParam);
UINT ThreadFunc2(LPVOID pParam);


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__92861564_1D56_481F_BF1F_2437C2CDA5A5__INCLUDED_)
