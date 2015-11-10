// ClientSock.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSock

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSock, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSock member functions

// 데이터가 전달되면 호출되는 통보 함수
void CClientSock::OnReceive(int nErrorCode) 
{
	((CClientApp*)AfxGetApp())->ReceiveData(); // 데이터를 읽는다.
	CAsyncSocket::OnReceive(nErrorCode);
}

// 연결된 소켓이 닫히면 호출되는 통보 함수
void CClientSock::OnClose(int nErrorCode) 
{
	((CClientApp*)AfxGetApp())->CloseChild();// 자신과 연결된 서버의 자소켓이 닫힘
	CAsyncSocket::OnClose(nErrorCode);
}
