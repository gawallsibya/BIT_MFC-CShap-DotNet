// Server.h : main header file for the SERVER application
//

#if !defined(AFX_SERVER_H__3214294C_5BC6_11D2_93C8_9D15DA22F20A__INCLUDED_)
#define AFX_SERVER_H__3214294C_5BC6_11D2_93C8_9D15DA22F20A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerApp:
// See Server.cpp for the implementation of this class
//
#include "ListenSock.h"
#include "ChildSock.h"
class CServerApp : public CWinApp
{
public:
	void InitServer(); // 서버 소켓을 초기화 한다.
	void CleanUp(); // 생성된 소켓을 닫고 메모리를 해제한다. 

	void SendData(char *SendData); // 데이터 전송
	void ReceiveData(CChildSock* pRecSock); // 데이터 수신
	void Accept(); // 새로운 클라이언트 접속시 호출
	void CloseChild(CChildSock* pCloseSock); // 연결된 소켓이 닫히면 호출

	CListenSock* m_pServer; // 클라언트의 접속을 위해 리슨(대기)하는 서버 소켓
//	CChildSock* m_pChild; // 새로운 클라이언트 접속 후 생성되는 자소켓
	CObList m_pSockList; // 클라이언트와 연결된 자소켓들을 관리
	CServerApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER_H__3214294C_5BC6_11D2_93C8_9D15DA22F20A__INCLUDED_)
