// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Map.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_CHILD_PROCESS, OnChildProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style &= ~FWS_ADDTOTITLE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText("보내는 프로그램");	
	return 0;
}

void CMainFrame::OnChildProcess() 
{
	AfxBeginThread(ChildInfo, NULL); // 작업 스레드 시작
}

UINT CMainFrame::ChildInfo(LPVOID lParam)
{
	// 자식 프로세스(Sub.exe)와의 동기화에 사용할 이벤트 객체 생성
	CEvent myEvent(FALSE, FALSE, "ParentEvent");
	// 메모리 맵 파일 생성
	HANDLE hFileMapping = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, 
		PAGE_READWRITE, 0, sizeof(DWORD), "spy");

	if(!hFileMapping)
	{
		AfxMessageBox("메모리 맵 생성 실패");
		return 0;
	}

	// 자식 프로세스를 생성하기 위한 준비 작업
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	// 자식 프로세스를 생성한다.
	if(CreateProcess("sub.exe", NULL, NULL, NULL, NULL, //TRUE, 
		NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
	{
		// 프로세스의 참조 횟수를 1로 맞추기 위해 
		// 미리 한번 닫는다.
//		CloseHandle(pi.hProcess);
		// 이벤트를 기다리는데 사용
		CSingleLock doKey(&myEvent);

		while(1) // 자식 프로세스가 종료될때까지 루프를 돈다.
		{
			// 자식 프로세스(Sub.exe)에서 이벤트가 발생할 때까지 
			// 대기 상태로 기다린다.
			doKey.Lock(); 
			// 이벤트가 발생되면 메모리 맵 파일에 무슨 내용이 
			// 있는지 확인한다.
			DWORD* pData = (DWORD*)MapViewOfFile(hFileMapping, 
				FILE_MAP_READ|FILE_MAP_WRITE,0,0,0);

			if(*pData == -1) // 자식 프로세스가 종료된 경우
			{
					AfxMessageBox("자식 프로세스 종료.");
					break;
			}
			else // 자식 프로세스가 작동중
			{	
				CString str;
				str.Format("메시지를 보내온 자식 프로세스의 ID \r\n %X", 
					*pData);
				AfxMessageBox(str);
				doKey.Unlock(1);
				myEvent.ResetEvent(); // 다시 대기 상태로 들어간다.
			}
		}
	} // if
	else
	{
		AfxMessageBox("자식 프로세스 생성 실패");
		return 0;
	}
	return 0;
}

