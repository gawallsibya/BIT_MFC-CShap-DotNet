// Widget.h: interface for the CWidget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WIDGET_H__A4C5A169_D616_4AFC_83D0_B58785346CD1__INCLUDED_)
#define AFX_WIDGET_H__A4C5A169_D616_4AFC_83D0_B58785346CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWidget  
{
public:
	virtual void Draw( CDC* ) = 0;
	CWidget();
	virtual ~CWidget();

};

#endif // !defined(AFX_WIDGET_H__A4C5A169_D616_4AFC_83D0_B58785346CD1__INCLUDED_)
