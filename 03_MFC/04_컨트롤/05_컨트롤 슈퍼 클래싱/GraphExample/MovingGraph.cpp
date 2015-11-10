// MovingGraph.cpp : implementation file
//

#include "stdafx.h"
#include "MovingGraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMovingGraph

CMovingGraph::CMovingGraph()
{
	m_limitColor = RGB(255,0,0);
	m_lineColor = RGB(0,255,0);

	m_nDX = 3;	// to be constant
	m_nOffset = 0;

	m_bFirst = TRUE;
	m_oldPoint.x = -1;
	m_oldPoint.y = -1;
	
}

CMovingGraph::~CMovingGraph()
{
	m_drawDC.DeleteDC();
	m_backDC.DeleteDC();
}


BEGIN_MESSAGE_MAP(CMovingGraph, CStatic)
	//{{AFX_MSG_MAP(CMovingGraph)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMovingGraph message handlers

void CMovingGraph::PreSubclassWindow() 
{
	ModifyStyle(0, BS_OWNERDRAW);
	
	CStatic::PreSubclassWindow();
}

void CMovingGraph::SetBackBitmap( UINT nBackBmpID )
{
	m_drawDC.DeleteDC();
	m_backDC.DeleteDC();

	m_nOffset=0;
	m_oldPoint.x = -1;
	m_oldPoint.y = -1;

	CBitmap bitmap1, bitmap2;
	bitmap1.LoadBitmap(nBackBmpID);
	bitmap2.LoadBitmap(nBackBmpID);

	CClientDC dc(this);
	m_backDC.CreateCompatibleDC(&dc);
	m_drawDC.CreateCompatibleDC(&dc);
	m_backDC.SelectObject(&bitmap1);
	m_drawDC.SelectObject(&bitmap2);
	
	BITMAP bm;
	bitmap1.GetBitmap(&bm);
		
	SetWindowPos( NULL, NULL, NULL, bm.bmWidth, bm.bmHeight, SWP_NOMOVE );
	Invalidate(TRUE);
}

void CMovingGraph::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(&rect);

	dc.BitBlt( 0,0, rect.Width(), rect.Height(), &m_drawDC, 0, 0, SRCCOPY );

	// Do not call CStatic::OnPaint() for painting messages
}

void CMovingGraph::DrawPoint(unsigned short nPoint)
{
	CRect rect;
	GetClientRect(&rect);

	int cx = rect.Width();
	int cy = rect.Height();
	
	m_drawDC.BitBlt( 0, 0, cx-m_nDX, cy, &m_drawDC, m_nDX, 0, SRCCOPY );

	int nSel = m_nOffset - ((cx-1)-m_nDX);

	m_drawDC.BitBlt( cx-m_nDX, 0, m_nDX, cy, &m_backDC, m_nOffset, 0, SRCCOPY );

	if(nSel>0)
	{		
		switch(nSel)
		{
		case 1:
			m_nOffset = 0;
			break;
		case 2:
			m_drawDC.BitBlt( cx-m_nDX+2, 0, 1, cy, &m_backDC, 0, 0, SRCCOPY );
			m_nOffset = 1;
			break;
		case 3:
			m_drawDC.BitBlt( cx-m_nDX+1, 0, 1, cy, &m_backDC, 0, 0, SRCCOPY );
			m_nOffset = 2;
			break;		
		}
	}
	else
	{
		m_nOffset+=m_nDX;
	}

	float nHeight = (float)rect.Height() * (float)((float)nPoint/100.);

	CPoint pnt;
	pnt.x = cx-1;
	pnt.y = (cy-1) - (int)nHeight;
	pnt.y<0 ? pnt.y=0 : 1;

	CPen pen( PS_SOLID, 1, m_lineColor ), penLimit( PS_SOLID, 1, m_limitColor ), *pOldPen;

	if(pnt.y==0)// condition of limit
		pOldPen = m_drawDC.SelectObject(&penLimit);
	else pOldPen = m_drawDC.SelectObject(&pen);

	if(m_oldPoint.x == -1 && m_oldPoint.y == -1 )
		m_drawDC.MoveTo(cx-1-m_nDX, cy-1 );
	else m_drawDC.MoveTo(m_oldPoint);

	m_drawDC.LineTo(pnt);

	pnt.x = cx-1-m_nDX;
	m_oldPoint = pnt;
	m_drawDC.SelectObject(pOldPen);
	
	Invalidate(TRUE);
}


