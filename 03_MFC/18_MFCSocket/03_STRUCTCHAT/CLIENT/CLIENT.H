// Client.h : main header file for the CLIENT application
//

#if !defined(AFX_CLIENT_H__99F4C3E6_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
#define AFX_CLIENT_H__99F4C3E6_5C5B_11D2_93C8_941A6CE10812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClientApp:
// See Client.cpp for the implementation of this class
//

#include "ClientSock.h"
class CClientApp : public CWinApp
{
public:
	void Connect(); // 서버로 접속
	void SendData(char *SendData); // 데이터 전송
	void ReceiveData(); // 데이터 수신
	void CloseChild(); // 연결된 소켓이 닫히면 호출
	void CleanUp(); // 생성된 소켓을 닫고 메모리를 해제한다. 
	CClientSock*  m_pClient; // 서버에 접속할 클라이언트 소켓 

	CClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT_H__99F4C3E6_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
