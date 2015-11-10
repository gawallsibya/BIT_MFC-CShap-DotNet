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
	//���α׷��� ��Ʈ���� �ѷ� ������ ���ؼ� ������ ũ�⸦ ����Ѵ�.
	CRect LeftRect, RightRect, ClientRect;
	GetClientRect(ClientRect);
	LeftRect = ClientRect;
	RightRect = ClientRect;
	//1%�� �ش��ϴ� ������ ũ�⸦ ����Ѵ�.
	//�׸���, �ѷ� �������� ���ʰ� ������ ������ ���ؼ� �ٸ� ������ ĥ�Ѵ�.
	LeftRect.right = (ClientRect.right * m_nData) / 100;
	RightRect.left = (ClientRect.right * m_nData) / 100;
	dc.FillSolidRect(LeftRect, RGB(0, 0, 128));
	dc.FillSolidRect(RightRect, RGB(255, 255, 255));
	//���ʰ� �������� �� �������� �����Ѵ�.
	CRgn LeftRgn, RightRgn;
	LeftRgn.CreateRectRgnIndirect(LeftRect);
	RightRgn.CreateRectRgnIndirect(RightRect);
	//���ʿ����� ���� ǥ�� �ؽ�Ʈ�� �߾� �����Ͽ� ����Ѵ�.
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 255, 255));
	dc.SelectClipRgn(&LeftRgn);
	dc.DrawText(tmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//������ ������ ���� ǥ�� �ؽ�Ʈ�� �߾� �����Ͽ� ����Ѵ�.
	dc.SetTextColor(RGB(0, 0, 128));
	dc.SelectClipRgn(&RightRgn);
	dc.DrawText(tmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
