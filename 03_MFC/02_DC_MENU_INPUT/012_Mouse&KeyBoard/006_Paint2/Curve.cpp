// Curve.cpp: implementation of the CCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sample.h"
#include "Curve.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCurve::CCurve()
{

}

CCurve::~CCurve()
{

}

CCurve::CCurve(const COLORREF &color)
{
   m_color			= color;                    // Store the color
   m_enclosingRect	= CRect(0,0,0,0);
   m_pen			= 1;                   // Set pen width

}

void CCurve::Draw(CDC *pDC) const
{

}
