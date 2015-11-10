// HTStatic.cpp : implementation file
//

#include "stdafx.h"
#include "HTStaticDemo.h"
#include "HTStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTStatic

CHTStatic::CHTStatic()
{
	m_hBrush = ::CreateSolidBrush(GetSysColor(COLOR_3DFACE));
	m_bMouseOn = FALSE;
	m_hCursor = NULL;
}

CHTStatic::~CHTStatic()
{
	::DeleteObject(m_hBrush);
}


BEGIN_MESSAGE_MAP(CHTStatic, CStatic)
	//{{AFX_MSG_MAP(CHTStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTStatic message handlers

void CHTStatic::PreSubclassWindow() 
{
	DWORD dwStyle = GetStyle();
	//서브 클래싱에 앞서서 메시지를 받을 수 있도록 스타일을 설정한다.
	::SetWindowLong(GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);
	
	CStatic::PreSubclassWindow();
}

void CHTStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(m_bMouseOn)
	{
		CRect rect;
		GetClientRect(rect);

		if(!rect.PtInRect(point))
		{
			//마우스 포인터가 컨트롤 밖으로 벗어났음.
			m_bMouseOn = FALSE;
			//텍스트 색상을 변경하도록 윈도우를 다시 그리고
			//마우스 캡쳐를 해제한다.
			RedrawWindow();
			ReleaseCapture();
			return;
		}
	}
	else
	{
		//마우스 포인터가 컨트롤 위에 있음.
		m_bMouseOn = TRUE;
		//글씨의 색을 변경하고 마우스를 캡쳐한다.
		RedrawWindow();
		SetCapture();
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

HBRUSH CHTStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	//스태틱 컨트롤에 해당하는 것인가?
	if(CTLCOLOR_STATIC == nCtlColor)
	{
		//마우스 포인터의 위치에 따라 텍스트 색상을 바꾼다.
		pDC->SetBkMode(TRANSPARENT);
		if(m_bMouseOn)		pDC->SetTextColor(RGB(0, 0, 255));
		else				pDC->SetTextColor(RGB(0, 0, 0));
	}

//	OutputDebugString("HT-=WM_CTLCOLOR");
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return m_hBrush;
}

HBRUSH CHTStatic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
//	OutputDebugString("HT-WM_CTLCOLOR");
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CHTStatic::OnLButtonDown(UINT nFlags, CPoint point) 
{
	TCHAR szBuffer[128];
	GetWindowText(szBuffer, 128);
	::ShellExecute(NULL, _T("open"), szBuffer, NULL, NULL, SW_SHOW);
	//브라우저가 실행되면 프로그램이 포커스를 잃게 되므로
	//이에 대한 처리를 반드시 해주어야 함.
	ReleaseCapture();
	m_bMouseOn = FALSE;

	CStatic::OnLButtonDown(nFlags, point);
}

BOOL CHTStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if(m_hCursor == NULL)	m_hCursor = ::LoadCursor(NULL, IDC_ARROW);
	if(m_hCursor)
	{
		::SetCursor(m_hCursor);
		return TRUE;
	}

	return FALSE;
//	return CStatic::OnSetCursor(pWnd, nHitTest, message);
}
