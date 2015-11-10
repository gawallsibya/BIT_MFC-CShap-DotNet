// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Single.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)			// (1)
/*
    (1) F12 : 정의된 곳으로 이동

        CreateObject의 정의
        IMPLEMENT_RUNTIMECLASS 매크로 호출
		-	Runtime class와 관계된 클래스 정적 맴버 변수를 초기화
		-	CRuntimeClass의 정보를 얻는 가상 함수 GetRuntimeClass()를 정의
*/


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()									// (2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/*
(2) WM_CREATE(윈도우 메시지) 에 대응하는 메크로
    #define ON_WM_CREATE() \
	{ WM_CREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))
	  & OnCreate },

		-	시그네처
		-	OnWndMsg에서 확인 가능…
		-	시그네처를 바탕으로 wParam lParam의 정보를 사용자 편의에 맞게 제공
		-	Lpcs = (LPCREATESTRUCT)lParam;		// API
		-	AfxSig_is,	// int(LPTSTR)
	Case AfxSig_is : 
 	lResult = (this->*mmf.pfn_is)((LPTSTR)lParam);	break;
*/


static UINT indicators[] =							// (3)
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
/*
	(3) 상태바의 지시자 : 중간에 ID_SEPARATOR 추가 ..
*/
/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}


// App::IninInstance()에서 호출되는 부분 
// a) 윈도우 클래스 등록
// b) PreCrateWindow(cs) 호출 
// b) CreateWindow 호출시 WM_CREATE 메시지 생성
// c) OnCreate 호출 
//    - 매개변수로 구조체 전달 
//    - 주로 프레임에 올릴 윈도우 생성 
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)	// (2_1)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)		// (5)
		return -1;
	/*
	(5) 왜 상위 클래스의 OnCreate를 먼저 호출할까?
        WM_CREATE 발생시점 : 
		   화면에 표시할 윈도우를 유지하는 윈도우 구조체를 
		   메모리에 할당한 후 발생(아직 화면에 윈도우가 그려지지 않음)
           따라서 상위 클래스의 OnCreate를 호출하여 먼저 프레임을 그린다.

		여기서는 툴바, 상태바등을 그리게 됨 

	*/
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))				// (4)상태바 교재 참조 
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	/*
	(4) 배열의 크기를 구하는 이상적인 방법
	    (수작업으로 변하는 코드를 코드변환없이 제공해줌)
	*/

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)	// (6)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	cs.cx	= 200;
	cs.cy	= 200;
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

