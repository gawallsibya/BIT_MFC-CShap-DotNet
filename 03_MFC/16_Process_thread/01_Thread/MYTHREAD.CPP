// MyThread.cpp : implementation file
//

#include "stdafx.h"
#include "Count.h"
#include "MyThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyThread

IMPLEMENT_DYNCREATE(CMyThread, CWinThread)

CMyThread::CMyThread()
{
}

CMyThread::~CMyThread()
{
}

BOOL CMyThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CMyThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread, CWinThread)
	//{{AFX_MSG_MAP(CMyThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThread message handlers

// 다이얼로그의 객체 포인터를 설정하는 함수
void CMyThread::SetOwner(CCountDlg *pDlg)
{
	m_pDlg = pDlg;
}

// 사용자 인터페이스 스레드가 수행하는 부분
int CMyThread::Run() 
{
	CProgressCtrl* pProgress =
		(CProgressCtrl*)m_pDlg->GetDlgItem(IDC_PROGRESS1);
	pProgress->SetRange(0, 1000); // 유효 범위 설정

	CString str;
	int idx = 0;
	for(int i = 0; i <= 1000; i++)
	{
		pProgress->SetPos(i); // 진행 위치 설정
		if(!(i%10))
		{
			str.Format("진행율 %d%%", idx++);
			m_pDlg->SetDlgItemText(IDC_PERCENT, str); // 진행율 표시
			Sleep(500);
		}
	}
	m_pDlg->GetDlgItem(IDC_START_PROGRESS)->EnableWindow(TRUE);
	AfxEndThread(0); // 사용자 인터페이스 스레드 종료
	return CWinThread::Run();
}
