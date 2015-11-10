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
	m_pChild = NULL;
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
	m_pChild = new CChildSock;  // 클라이언트와 연결할 자소켓 객체 
	m_pServer->Accept(*m_pChild); // 클라이언트의 접속을 허용하고 자소켓과 연결한다.
								  // 그리고나서 서버 소켓은 새로운 클라이언트의 
								  // 연결 요청을 기다리며 대기한다.
	m_pMainWnd->GetDlgItem(IDC_SEND)->EnableWindow(TRUE); // [보내기]버튼 활성화
}


void CServerApp::SendData(CString &strData)
{
	if(m_pChild)
	{
	// 클라이언트와 연결된 자소켓을 이용하여 데이터를 보낸다.
	m_pChild->Send((LPCSTR)strData,	strData.GetLength()+1);

	CString strText;
	UINT    nPort;
	m_pChild->GetSockName(strText, nPort);// 자신의 IP 주소와 포트 번호 얻음
	strText = "[ " + strText + " ] " + strData;
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	}
}

void CServerApp::ReceiveData()
{
	// 현재 클라이언트와 연결된 자소켓을 이용하여 데이터를 받는다.
	char temp[1000];
	m_pChild->Receive(temp, sizeof(temp));

	CString strText;
	UINT    nPort;
	m_pChild->GetPeerName(strText, nPort); // 상대방의 IP 주소와 포트 번호 얻음
	strText = "[ " + strText + " ] " + temp;
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}

void CServerApp::CleanUp()
{	// 생성된 소켓을 닫고 메모리를 해제한다.
	if(m_pServer)
		delete m_pServer;
	if(m_pChild)
		delete m_pChild;
}

void CServerApp::CloseChild()
{
	AfxMessageBox("연결된 상대방 소켓 닫힘");
	m_pChild->Close();
	delete m_pChild;
	m_pMainWnd->GetDlgItem(IDC_SEND)->EnableWindow(FALSE); // [보내기]버튼 비활성화
}
