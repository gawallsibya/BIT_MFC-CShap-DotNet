// MyExplorerDoc.h : interface of the CMyExplorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYEXPLORERDOC_H__03F781F1_B76F_40DE_B2FE_33C3542EFBDA__INCLUDED_)
#define AFX_MYEXPLORERDOC_H__03F781F1_B76F_40DE_B2FE_33C3542EFBDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyExplorerDoc : public COleDocument
{
protected: // create from serialization only
	CMyExplorerDoc();
	DECLARE_DYNCREATE(CMyExplorerDoc)

	CObList *m_pFileList;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyExplorerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void RemoveAllFileList();
	void InitListViewStruct(LIST_VIEW* pListView);
	void SelectTreeViewFolder(CString strFullName);
	void GetChildFolders(CStringArray* strFolderList, CString strParentFolder);
	virtual ~CMyExplorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyExplorerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEXPLORERDOC_H__03F781F1_B76F_40DE_B2FE_33C3542EFBDA__INCLUDED_)
