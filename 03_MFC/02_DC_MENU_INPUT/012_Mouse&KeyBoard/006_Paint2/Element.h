// Element.h: interface for the CElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMENT_H__08194BAB_DEF4_432C_B09B_B0CC9FA892F8__INCLUDED_)
#define AFX_ELEMENT_H__08194BAB_DEF4_432C_B09B_B0CC9FA892F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElement : public CObject  
{
protected:
	COLORREF	m_color;			// color of an element
	CRect		m_enclosingRect;	// Rectangle enclosing an slement
	int			m_pen;				// pen width
public:

	// 생성자 & 소멸자 
	CElement();
	virtual ~CElement();

	// Get & Set
	CRect GetBoundRect() const;

	// method
	virtual void Draw(CDC *pDC) const;	// 가상 Draw 함수
};


#endif // !defined(AFX_ELEMENT_H__08194BAB_DEF4_432C_B09B_B0CC9FA892F8__INCLUDED_)
