// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sample.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine(const CPoint &start, const CPoint &end, const COLORREF &color)
{

	m_startPoint	= start;
	m_endPoint		= end;
	m_color			= color;
	m_pen			= 1;

	m_enclosingRect	= CRect(start, end);
	m_enclosingRect.NormalizeRect();
}


CLine::CLine()
{

}

CLine::~CLine()
{

}

void CLine::Draw(CDC *pDC) const
{
	CPen aPen;
	if(!aPen.CreatePen(PS_SOLID, m_pen, m_color))
	{
		// Pen creation failed. Abort the program
		AfxMessageBox("Pen creation failed drawing a line", MB_OK);
		AfxAbort();
	}
	
	CPen* pOldPen = pDC->SelectObject(&aPen);  // Select the pen
	// Now draw the line
	pDC->MoveTo(m_startPoint);
	pDC->LineTo(m_endPoint);
	
	pDC->SelectObject(pOldPen);                // Restore the old pen
}
