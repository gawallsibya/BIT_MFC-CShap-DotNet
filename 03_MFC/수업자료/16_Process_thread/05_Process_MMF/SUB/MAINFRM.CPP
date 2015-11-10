// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Sub.h"

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
	ON_WM_DESTROY()
	ON_COMMAND(ID_PARENT_SEND, OnParentSend)
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
	
	SetWindowText("받는 프로그램");	
	return 0;
}



void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	CEvent myEvent(FALSE, FALSE, "ParentEvent");
	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, "spy");
	if(!hFileMapping)
		return;

	DWORD* pData = (DWORD*)MapViewOfFile(hFileMapping, FILE_MAP_WRITE,
		0,0,0);
	if(!pData)
		return ;

	*pData = -1;
	myEvent.SetEvent();
	UnmapViewOfFile(pData);
	CloseHandle(hFileMapping);
}

void CMainFrame::OnParentSend() 
{
	CEvent myEvent(FALSE, FALSE, "ParentEvent");
	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, "spy");
	if(!hFileMapping)
		return;

	DWORD* pData = (DWORD*)MapViewOfFile(hFileMapping, FILE_MAP_WRITE,
		0,0,0);
	if(!pData)
		return ;

	*pData = GetCurrentProcessId();
	myEvent.SetEvent();
	UnmapViewOfFile(pData);
	CloseHandle(hFileMapping);
}
