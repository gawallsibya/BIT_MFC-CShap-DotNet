// Client.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "ConnectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientApp

BEGIN_MESSAGE_MAP(CClientApp, CWinApp)
	//{{AFX_MSG_MAP(CClientApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientApp construction

CClientApp::CClientApp()
{
	m_pClient = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CClientApp object

CClientApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CClientApp initialization

BOOL CClientApp::InitInstance()
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

	CClientDlg dlg;
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
void CClientApp::Connect() // 서버에 연결한다.
{
	CConnectDlg  dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_pClient = new CClientSock; // 클라이언트 소켓 객체
		m_pClient->Create(); // 클라이언트 소켓 생성
		// 서버의 IP 주소와 포트 번호를 설정하여 
		// 서버에 연결을 시도한다.
		m_pClient->Connect(dlg.m_strAddress, 7000); 
		m_pMainWnd->GetDlgItem(IDC_SEND)->EnableWindow(TRUE); // [보내기]버튼 활성화
		m_pMainWnd->GetDlgItem(IDC_CONNECT)->EnableWindow(FALSE); // [서버 연결...]버튼 비활성화
	}
}

void CClientApp::SendData(CString& strData)
{
	if(m_pClient)
	{
	// 클라이언트 소켓을 이용하여 데이터를 보낸다.
	m_pClient->Send((LPCSTR)strData, strData.GetLength()+1);

	CString strText;
	UINT    nPort;
	m_pClient->GetSockName(strText, nPort);// 자신의 IP 주소와 포트 번호 얻음
	strText = "[ " + strText + " ] " + strData;
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	}
}

void CClientApp::ReceiveData()
{
	char temp[1000];
	m_pClient->Receive(temp, sizeof(temp));

	CString strText;
	UINT    nPort;
	m_pClient->GetPeerName(strText, nPort); // 상대방의 IP 주소와 포트 번호 얻음
	strText = "[ " + strText + " ] " + temp;
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}


void CClientApp::CleanUp()
{	// 생성된 소켓을 닫고 메모리를 해제한다.
	if(m_pClient)
		delete m_pClient;
}

void CClientApp::CloseChild()
{
	AfxMessageBox("상대방 소켓 닫힘");
	m_pMainWnd->GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
}

