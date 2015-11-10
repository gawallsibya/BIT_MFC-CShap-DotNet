// Data.h: interface for the CData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__F4F17AB6_23C5_4593_AC7E_1D04D9EC901D__INCLUDED_)
#define AFX_DATA_H__F4F17AB6_23C5_4593_AC7E_1D04D9EC901D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CData  : public CObject
{

public:
	void SetData(CPoint _a, CPoint _b);
	void Serialize(CArchive &ar);
	CPoint a;
	CPoint b;
	CData();
	virtual ~CData();
	

};

#endif // !defined(AFX_DATA_H__F4F17AB6_23C5_4593_AC7E_1D04D9EC901D__INCLUDED_)
