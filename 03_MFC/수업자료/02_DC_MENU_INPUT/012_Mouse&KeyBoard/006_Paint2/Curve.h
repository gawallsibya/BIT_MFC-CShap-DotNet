// Curve.h: interface for the CCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURVE_H__4A0467C3_13D7_40E0_8B68_E567734EEACB__INCLUDED_)
#define AFX_CURVE_H__4A0467C3_13D7_40E0_8B68_E567734EEACB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Element.h"

class CCurve : public CElement  
{
public:
	virtual void Draw( CDC *pDC) const;
	CCurve( const COLORREF & color);
	CCurve();
	virtual ~CCurve();

};

#endif // !defined(AFX_CURVE_H__4A0467C3_13D7_40E0_8B68_E567734EEACB__INCLUDED_)
