// ListenSock.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ListenSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListenSock

CListenSock::CListenSock()
{
}

CListenSock::~CListenSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CListenSock, CAsyncSocket)
	//{{AFX_MSG_MAP(CListenSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CListenSock member functions

// 새로운 클라이언트의 연결 요청이 있으면 호출되는 통보 함수
void CListenSock::OnAccept(int nErrorCode) 
{	
	((CServerApp*)AfxGetApp())->Accept(); // 접속 허용을 위해 호출
	CAsyncSocket::OnAccept(nErrorCode);
}
