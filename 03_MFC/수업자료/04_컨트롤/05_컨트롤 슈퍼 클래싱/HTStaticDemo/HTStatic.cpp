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
	//���� Ŭ���̿� �ռ��� �޽����� ���� �� �ֵ��� ��Ÿ���� �����Ѵ�.
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
			//���콺 �����Ͱ� ��Ʈ�� ������ �����.
			m_bMouseOn = FALSE;
			//�ؽ�Ʈ ������ �����ϵ��� �����츦 �ٽ� �׸���
			//���콺 ĸ�ĸ� �����Ѵ�.
			RedrawWindow();
			ReleaseCapture();
			return;
		}
	}
	else
	{
		//���콺 �����Ͱ� ��Ʈ�� ���� ����.
		m_bMouseOn = TRUE;
		//�۾��� ���� �����ϰ� ���콺�� ĸ���Ѵ�.
		RedrawWindow();
		SetCapture();
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

HBRUSH CHTStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	//����ƽ ��Ʈ�ѿ� �ش��ϴ� ���ΰ�?
	if(CTLCOLOR_STATIC == nCtlColor)
	{
		//���콺 �������� ��ġ�� ���� �ؽ�Ʈ ������ �ٲ۴�.
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
	//�������� ����Ǹ� ���α׷��� ��Ŀ���� �Ұ� �ǹǷ�
	//�̿� ���� ó���� �ݵ�� ���־�� ��.
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
