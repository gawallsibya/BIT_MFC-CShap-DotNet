// Data.h: interface for the CData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__F42B9D9B_B8C5_4DA7_985F_61D975651BC4__INCLUDED_)
#define AFX_DATA_H__F42B9D9B_B8C5_4DA7_985F_61D975651BC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CData   : public CObject
{
public:
	void Serialize( CArchive &ar);
	CData();
	virtual ~CData();

	CPoint		m_ptHead;
	CPoint		m_ptTail;
	int			m_nType;
	COLORREF	m_colorPen;
	COLORREF	m_colorBrush;
};

#endif // !defined(AFX_DATA_H__F42B9D9B_B8C5_4DA7_985F_61D975651BC4__INCLUDED_)
