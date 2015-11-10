// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__8810A022_DE4C_4DA5_8E71_8C1F678F2373__INCLUDED_)
#define AFX_LINE_H__8810A022_DE4C_4DA5_8E71_8C1F678F2373__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Element.h"

class CLine : public CElement  
{
protected:
	CPoint		m_startPoint;		// start point of line
	CPoint		m_endPoint;			// end   point of line

public:

	// 持失切 & 社瑚切 
	CLine();
	CLine( const CPoint &start, const CPoint &end, const COLORREF &color);
	virtual ~CLine();

	// method
	virtual void Draw(CDC *pDC) const;

};

#endif // !defined(AFX_LINE_H__8810A022_DE4C_4DA5_8E71_8C1F678F2373__INCLUDED_)
