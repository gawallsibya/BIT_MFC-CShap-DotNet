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
    (1) F12 : ���ǵ� ������ �̵�

        CreateObject�� ����
        IMPLEMENT_RUNTIMECLASS ��ũ�� ȣ��
		-	Runtime class�� ����� Ŭ���� ���� �ɹ� ������ �ʱ�ȭ
		-	CRuntimeClass�� ������ ��� ���� �Լ� GetRuntimeClass()�� ����
*/


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()									// (2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/*
(2) WM_CREATE(������ �޽���) �� �����ϴ� ��ũ��
    #define ON_WM_CREATE() \
	{ WM_CREATE, 0, 0, 0, AfxSig_is, \
		(AFX_PMSG)(AFX_PMSGW)(int (AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT))
	  & OnCreate },

		-	�ñ׳�ó
		-	OnWndMsg���� Ȯ�� ���ɡ�
		-	�ñ׳�ó�� �������� wParam lParam�� ������ ����� ���ǿ� �°� ����
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
	(3) ���¹��� ������ : �߰��� ID_SEPARATOR �߰� ..
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


// App::IninInstance()���� ȣ��Ǵ� �κ� 
// a) ������ Ŭ���� ���
// b) PreCrateWindow(cs) ȣ�� 
// b) CreateWindow ȣ��� WM_CREATE �޽��� ����
// c) OnCreate ȣ�� 
//    - �Ű������� ����ü ���� 
//    - �ַ� �����ӿ� �ø� ������ ���� 
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)	// (2_1)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)		// (5)
		return -1;
	/*
	(5) �� ���� Ŭ������ OnCreate�� ���� ȣ���ұ�?
        WM_CREATE �߻����� : 
		   ȭ�鿡 ǥ���� �����츦 �����ϴ� ������ ����ü�� 
		   �޸𸮿� �Ҵ��� �� �߻�(���� ȭ�鿡 �����찡 �׷����� ����)
           ���� ���� Ŭ������ OnCreate�� ȣ���Ͽ� ���� �������� �׸���.

		���⼭�� ����, ���¹ٵ��� �׸��� �� 

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
		  sizeof(indicators)/sizeof(UINT)))				// (4)���¹� ���� ���� 
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	/*
	(4) �迭�� ũ�⸦ ���ϴ� �̻����� ���
	    (���۾����� ���ϴ� �ڵ带 �ڵ庯ȯ���� ��������)
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

