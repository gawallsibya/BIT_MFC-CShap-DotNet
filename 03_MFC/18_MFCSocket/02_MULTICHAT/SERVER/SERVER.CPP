// Server.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerApp

BEGIN_MESSAGE_MAP(CServerApp, CWinApp)
	//{{AFX_MSG_MAP(CServerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerApp construction

CServerApp::CServerApp()
{
	m_pServer = NULL;
//	m_pChild = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CServerApp object

CServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CServerApp initialization

BOOL CServerApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CServerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
//=======================================================
// 추가된 코드 내용 
void CServerApp::InitServer()
{
	m_pServer = new CListenSock; // 리슨(대기)하는 서버 소켓 객체
	m_pServer->Create(7000); // 포트 번호 7000으로 서버 소켓 생성
	m_pServer->Listen(); // 클라이언트의 연결 요청을 기다리며 대기한다.
}

void CServerApp::Accept()
{
	AfxMessageBox("접속 허용...");
	CChildSock* pChild = new CChildSock;
	if(!m_pServer->Accept(*pChild)) 
			AfxMessageBox("접속 허용 실패"); 

	m_pSockList.AddTail(pChild); // 생성된 자소켓을 리스트에 추가
	int nCount = m_pSockList.GetCount(); 
	m_pMainWnd->SetDlgItemInt(IDC_USERCOUNT, nCount); // 현재 접속된 클라이언트 수 출력
}


void CServerApp::SendData(CString &strData)
{
	// 서버에 접속중인 모든 클라이언트에 데이터를 전송한다.
	CChildSock* pChild;
	POSITION pos = m_pSockList.GetHeadPosition();								
	while(pos != NULL)
	{
		pChild = (CChildSock*)m_pSockList.GetAt(pos);
		pChild->Send((LPCSTR)strData, strData.GetLength()+1);
		m_pSockList.GetNext(pos);
	}

	// 전송한 데이터를 리스트 박스에 추가한다.
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strData);
}

void CServerApp::ReceiveData(CChildSock* pRecSock)
{
	// 데이터를 수신하고 리스트 박스에 추가한다.
	char temp[1000];
	pRecSock->Receive(temp, sizeof(temp));
    CString strText;
	UINT    nPort;
	pRecSock->GetPeerName(strText, nPort); // 상대방의 IP 주소와 포트 번호 얻음
	strText = "[ " + strText + " ] " + temp;
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);	
	
	// 수신한 데이터를 서버에 접속중인 다른 클라이언트에 전송한다.
	CChildSock* pChild;
	POSITION pos = m_pSockList.GetHeadPosition();								
	while( pos !=NULL)  
	{
		pChild = (CChildSock*)m_pSockList.GetAt(pos);
		if(pChild != pRecSock)
		{
			pChild->Send(temp, sizeof(temp));
		}
		m_pSockList.GetNext(pos);
	}

}

void CServerApp::CleanUp()
{	// 자소켓을 관리하는 리스트를 모두 제거하는 부분
	CChildSock* pChild;
	while(!m_pSockList.IsEmpty())
	{   
		pChild = (CChildSock*)m_pSockList.RemoveHead();
		delete pChild;
	}

	// 서버 소켓 제거
	if(m_pServer)
		delete m_pServer;
}

void CServerApp::CloseChild(CChildSock* pCloseSock)
{
	AfxMessageBox("연결된 상대방 소켓 닫힘");
	// 현재 닫힌 소켓을 리스트에서 제거한다.
	CChildSock* pChild;
	POSITION pos = m_pSockList.GetHeadPosition();								
	while( pos !=NULL)
	{
		pChild = (CChildSock*)m_pSockList.GetAt(pos);
		if(pChild == pCloseSock) 
		{
			m_pSockList.RemoveAt(pos);
			delete pChild;
			break;
		}
		m_pSockList.GetNext(pos);
	}
	int nCount = m_pSockList.GetCount(); 
	m_pMainWnd->SetDlgItemInt(IDC_USERCOUNT, nCount); // 현재 접속된 클라이언트 수 출력
}
