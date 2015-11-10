// Sample3Doc.h : interface of the CSample3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE3DOC_H__723C135C_9B2A_419B_9E93_F8E7EF7A1D5E__INCLUDED_)
#define AFX_SAMPLE3DOC_H__723C135C_9B2A_419B_9E93_F8E7EF7A1D5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample3Doc : public CDocument
{
protected: // create from serialization only
	CSample3Doc();
	DECLARE_DYNCREATE(CSample3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE3DOC_H__723C135C_9B2A_419B_9E93_F8E7EF7A1D5E__INCLUDED_)
