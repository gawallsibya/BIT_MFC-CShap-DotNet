// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC Shape.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRectangle::CRectangle()
{

}

CRectangle::~CRectangle()
{

}

void CRectangle::Draw(CDC *pDC)
{
	pDC->Rectangle( m_x1, m_y1, m_x2, m_y2 );
}
