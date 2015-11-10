// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__8FC96DE5_68D1_4AB6_A620_DE839ED3BAAA__INCLUDED_)
#define AFX_RECTANGLE_H__8FC96DE5_68D1_4AB6_A620_DE839ED3BAAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Element.h"

class CRectangle : public CElement  
{
public:

	// 持失切 & 社瑚切 
	CRectangle();
	CRectangle( const CPoint &start, const CPoint &end, const COLORREF & color);
	virtual ~CRectangle();

	// method
	virtual void Draw( CDC *pDC) const;

};

#endif // !defined(AFX_RECTANGLE_H__8FC96DE5_68D1_4AB6_A620_DE839ED3BAAA__INCLUDED_)
