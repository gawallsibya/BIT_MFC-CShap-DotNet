// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__675A784A_B7C3_45AE_9D60_56031AE5AE6B__INCLUDED_)
#define AFX_RECTANGLE_H__675A784A_B7C3_45AE_9D60_56031AE5AE6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Widget.h"

class CRectangle : public CWidget  
{
	int m_x1, m_y1, m_x2, m_y2;

public:
	CRectangle( int x1, int y1, int x2, int y2 )
		: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

	virtual void Draw( CDC* pDC );
	CRectangle();
	virtual ~CRectangle();

};

#endif // !defined(AFX_RECTANGLE_H__675A784A_B7C3_45AE_9D60_56031AE5AE6B__INCLUDED_)
