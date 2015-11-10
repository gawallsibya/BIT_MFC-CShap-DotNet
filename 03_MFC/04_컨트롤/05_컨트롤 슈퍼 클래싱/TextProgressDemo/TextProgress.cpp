// TextProgress.cpp : implementation file
//

#include "stdafx.h"
#include "TextProgressDemo.h"
#include "TextProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextProgress

CTextProgress::CTextProgress()
{
	m_nData = 0;
}

CTextProgress::~CTextProgress()
{
}


BEGIN_MESSAGE_MAP(CTextProgress, CProgressCtrl)
	//{{AFX_MSG_MAP(CTextProgress)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextProgress message handlers

void CTextProgress::InitProgress()
{
	SetRange(0, 100);
	SetPos(0);
}

void CTextProgress::SetValue(int nNewData)
{
	m_nData = nNewData;
	RedrawWindow();
}

void CTextProgress::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CString tmp = _T("");
	tmp.Format("%d%%", m_nData);
	//프로그래스 컨트롤을 둘로 나누기 위해서 윈도우 크기를 계산한다.
	CRect LeftRect, RightRect, ClientRect;
	GetClientRect(ClientRect);
	LeftRect = ClientRect;
	RightRect = ClientRect;
	//1%에 해당하는 윈도우 크기를 계산한다.
	//그리고, 둘로 나누어진 왼쪽과 오른쪽 각각에 대해서 다른 색으로 칠한다.
	LeftRect.right = (ClientRect.right * m_nData) / 100;
	RightRect.left = (ClientRect.right * m_nData) / 100;
	dc.FillSolidRect(LeftRect, RGB(0, 0, 128));
	dc.FillSolidRect(RightRect, RGB(255, 255, 255));
	//왼쪽과 오른쪽을 두 영역으로 구분한다.
	CRgn LeftRgn, RightRgn;
	LeftRgn.CreateRectRgnIndirect(LeftRect);
	RightRgn.CreateRectRgnIndirect(RightRect);
	//왼쪽영역에 비율 표시 텍스트를 중앙 정렬하여 출력한다.
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 255, 255));
	dc.SelectClipRgn(&LeftRgn);
	dc.DrawText(tmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//오른쪽 영역에 비율 표시 텍스트를 중앙 정렬하여 출력한다.
	dc.SetTextColor(RGB(0, 0, 128));
	dc.SelectClipRgn(&RightRgn);
	dc.DrawText(tmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
