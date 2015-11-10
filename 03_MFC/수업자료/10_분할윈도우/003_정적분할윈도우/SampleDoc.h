// SampleDoc.h : interface of the CSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLEDOC_H__FDE967CA_088E_49DD_A60F_58B66F3EEC2C__INCLUDED_)
#define AFX_SAMPLEDOC_H__FDE967CA_088E_49DD_A60F_58B66F3EEC2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

struct Line
{
	CPoint ptFrom;
	CPoint ptTo;

	Line( CPoint p1, CPoint p2) : ptFrom(p1), ptTo(p2) {}
};

class CSampleDoc : public CDocument
{
protected: // create from serialization only
	CSampleDoc();
	DECLARE_DYNCREATE(CSampleDoc)

// Attributes
public:
	CList<Line*, Line*>	m_list;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEDOC_H__FDE967CA_088E_49DD_A60F_58B66F3EEC2C__INCLUDED_)
