// Element.cpp: implementation of the CElement class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sample.h"
#include "Element.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CElement::CElement()
{

}

CElement::~CElement()
{

}

void CElement::Draw(CDC *pDC) const
{

}

CRect CElement::GetBoundRect() const
{
	return m_enclosingRect;
}
