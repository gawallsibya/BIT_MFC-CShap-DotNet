// ExplorerTestDoc.h : interface of the CExplorerTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLORERTESTDOC_H__4798FD6B_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_EXPLORERTESTDOC_H__4798FD6B_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "data.h"

class	CExplorerTestView;
/////////////////////////////////////////////////////////////////////////////

class CExplorerTestDoc : public COleDocument
{
protected: // create from serialization only
	CExplorerTestDoc();
	DECLARE_DYNCREATE(CExplorerTestDoc)

public:
	void		GetChildFolders(CStringArray* strFolderList, CString strParentFolder);
	void		SetListViewPointer(CExplorerTestView* pListView);
	void		SelectTreeViewFolder(CString strFullName);
	BOOL		DeleteReadOnlyFile(CString strPath);

	CObList*	GetFileList();
	CString		GetCurrentPath();

	void		SetCopyFileList(CObList* pFileList);
	void		SerializeCopyFiles(CArchive& ar);
	CObList*	GetCopyFileList();

private:
	// variables
	CExplorerTestView*		m_pExpListView;

	CObList*		m_pFileList;
	CObList			m_copyFileList;

	CString			m_strCurrentPath;

	// functions
	void		RemoveAllFileList();
	void		SetCurrentPath(CString strCurrentPath);
	void		InitListViewStruct(LIST_VIEW* pListView);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplorerTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExplorerTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExplorerTestDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORERTESTDOC_H__4798FD6B_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
