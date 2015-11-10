// MSNButton.cpp : implementation file
//

#include "stdafx.h"
#include "MSNButtonDemo.h"
#include "MSNButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSNButton

CMSNButton::CMSNButton()
{
	m_bTracking = FALSE;
	m_bHover = FALSE;
}

CMSNButton::~CMSNButton()
{
}


BEGIN_MESSAGE_MAP(CMSNButton, CButton)
	//{{AFX_MSG_MAP(CMSNButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSNButton message handlers

void CMSNButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	//���콺 Ʈ��ŷ�� ���۵Ǿ��°�?
	if(!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bTracking = _TrackMouseEvent(&tme);
	}

	CButton::OnMouseMove(nFlags, point);
}

void CMSNButton::OnMouseHover(WPARAM wparam, LPARAM lparam) 
{
	//���콺 �����Ͱ� ��ư ������ �����̰� ����
	m_bHover=TRUE;
	RedrawWindow();
}

LRESULT CMSNButton::OnMouseLeave(WPARAM wparam, LPARAM lparam)
{
	//���콺 �����Ͱ� ��ư ������ ������
	m_bTracking = FALSE;
	m_bHover=FALSE;
	RedrawWindow();
	return 0;
}

void CMSNButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	//���� ��ο� ��Ʈ���� �׸��� �κ�
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	BITMAP bmpInfo;
	CBitmap Bmp;
	CBitmap* pOldBitmap = NULL;
	Bmp.LoadBitmap(IDB_Bitmap_Button);
	Bmp.GetBitmap(&bmpInfo);

	pOldBitmap = MemDC.SelectObject(&Bmp);
	//��ư�� ���õǾ��°�?
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		//�� ��° ��ư �̹��� ���
		pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 206, 0, SRCCOPY);
	}
	else
	{
		//���콺 �����Ͱ� ��ư ���� �����ϴ� ��?
		if(m_bHover)
		{
			//�� ��° ��ư �̹��� ���
			pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 103, 0, SRCCOPY);
		}
		else
		{
			//ù ��° ��ư �̹��� ���
			pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
		}	

	}

	MemDC.SelectObject(pOldBitmap);
}
