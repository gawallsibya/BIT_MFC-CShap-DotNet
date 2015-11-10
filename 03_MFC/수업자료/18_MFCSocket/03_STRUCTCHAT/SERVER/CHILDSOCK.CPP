// ChildSock.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ChildSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildSock

CChildSock::CChildSock()
{
}

CChildSock::~CChildSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CChildSock, CAsyncSocket)
	//{{AFX_MSG_MAP(CChildSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CChildSock member functions

// 데이터가 전달되면 호출되는 통보 함수
void CChildSock::OnReceive(int nErrorCode) 
{
	((CServerApp*)AfxGetApp())->ReceiveData(this); // 데이터를 읽는다.
	CAsyncSocket::OnReceive(nErrorCode);
}

// 연결된 소켓이 닫히면 호출되는 통보 함수
void CChildSock::OnClose(int nErrorCode) 
{
	((CServerApp*)AfxGetApp())->CloseChild(this); // 닫힌 소켓과 연결된 자소켓에 대해 처리한다. 
	CAsyncSocket::OnClose(nErrorCode);
}
