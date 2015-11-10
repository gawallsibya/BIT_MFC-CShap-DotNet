// GraphStatic.cpp : implementation file
//

#include "stdafx.h"
#include "HTStaticDemo.h"
#include "GraphStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphStatic

CGraphStatic::CGraphStatic()
{
	m_nData = 0;
}

CGraphStatic::~CGraphStatic()
{
}


BEGIN_MESSAGE_MAP(CGraphStatic, CStatic)
	//{{AFX_MSG_MAP(CGraphStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphStatic message handlers

void CGraphStatic::SetData(int nNewData)
{
	m_nData = nNewData;
	RedrawWindow();
}

void CGraphStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	//����� ���� ������ ĥ�Ѵ�.
	CRect Rect;
	CBrush* pNewBrush = new CBrush(RGB(0, 0, 0));
	dc.SelectObject(pNewBrush);

	GetClientRect(&Rect);
	dc.Rectangle(&Rect);
	delete pNewBrush;

	//���� ���� �ؽ�Ʈ�� ����Ѵ�.
	char szBuffer[32];
	dc.SetTextColor(RGB(0, 255, 0));
	dc.SetBkColor(RGB(0, 0, 0));
	sprintf(szBuffer, "%d%%", m_nData);
	dc.TextOut(10, 10, szBuffer);

	//��� �׷����� �׸���.
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 128, 0);

	CPen* pNewPen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT, 4, &lb);
	dc.SelectObject(pNewPen);
	for(int i = 10; i > 0; --i)
	{
		dc.MoveTo(CPoint(10, i * 6 + 30));
		dc.LineTo(CPoint(90, i * 6 + 30));
	}
	delete pNewPen;

	//m_nData ���� �ٰ��� �׷����� �׸���.
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 255, 0);
	pNewPen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT, 4, &lb);
	dc.SelectObject(pNewPen);
	for(i = 10; i > 10 - m_nData / 10; --i)
	{
		dc.MoveTo(CPoint(10, i * 6 + 30));
		dc.LineTo(CPoint(90, i * 6 + 30));
	}

	delete pNewPen;
	// Do not call CStatic::OnPaint() for painting messages
}

