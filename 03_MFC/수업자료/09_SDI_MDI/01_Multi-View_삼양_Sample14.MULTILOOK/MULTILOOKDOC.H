// MultiLookDoc.h : interface of the CMultiLookDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTILOOKDOC_H__F9DB2CC7_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
#define AFX_MULTILOOKDOC_H__F9DB2CC7_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiLookDoc : public CDocument
{
protected: // create from serialization only
	CMultiLookDoc();
	DECLARE_DYNCREATE(CMultiLookDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiLookDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiLookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiLookDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTILOOKDOC_H__F9DB2CC7_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
