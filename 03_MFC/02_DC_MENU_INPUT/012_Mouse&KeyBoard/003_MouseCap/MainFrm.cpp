// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MouseCap.h"

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
	ON_WM_NCLBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bCaptureEnabled	= TRUE;

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


void CMainFrame::OnNcLButtonDown(UINT nHitTest, CPoint point) 
{
	
	// 창의 제목 표시줄이 클릭되었을 때 캡쳐 플래그를 On과 OFF로 
	// 토글하고 창 제목 갱신
	if( nHitTest == HTCAPTION)
	{
		m_bCaptureEnabled = m_bCaptureEnabled ? FALSE : TRUE;

		SetWindowText(m_bCaptureEnabled  ? 
			_T("Mouse Capture Demo ( Capture Enabled)") :
			_T("Mouse Capture Demo ( Capture Disabled)"));
	}
	CFrameWnd::OnNcLButtonDown(nHitTest, point);
}
