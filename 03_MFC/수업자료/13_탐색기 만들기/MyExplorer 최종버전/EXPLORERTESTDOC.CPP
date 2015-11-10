// ExplorerTestDoc.cpp : implementation of the CExplorerTestDoc class
//

#include "stdafx.h"
#include "ExplorerTest.h"

#include "ExplorerTestDoc.h"
#include "CntrItem.h"
//
#include "ExplorerTestView.h"
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc

IMPLEMENT_DYNCREATE(CExplorerTestDoc, COleDocument)

BEGIN_MESSAGE_MAP(CExplorerTestDoc, COleDocument)
	//{{AFX_MSG_MAP(CExplorerTestDoc)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc construction/destruction

CExplorerTestDoc::CExplorerTestDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here
	m_pFileList = NULL;
}

CExplorerTestDoc::~CExplorerTestDoc()
{
	if (m_pFileList != NULL)
		RemoveAllFileList();
}

BOOL CExplorerTestDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc serialization

void CExplorerTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc diagnostics

#ifdef _DEBUG
void CExplorerTestDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CExplorerTestDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc public functions

void CExplorerTestDoc::GetChildFolders(CStringArray* strFolderList, CString strParentFolder)
{
	CFileFind	ff;

	if (strParentFolder.Right(1) != '\\')
	{
		strParentFolder += '\\';
	}

	strParentFolder += "*.*";

	if (ff.FindFile(strParentFolder) == TRUE)
	{
		BOOL	bFlag = TRUE;
		while(bFlag == TRUE)
		{
			bFlag = ff.FindNextFile();
			if (ff.IsDirectory() && !ff.IsDots())
				strFolderList->Add(ff.GetFileName());
		}
	}
	ff.Close();
}

void CExplorerTestDoc::SetListViewPointer(CExplorerTestView* pListView)
{
	m_pExpListView = pListView;
}

void CExplorerTestDoc::SelectTreeViewFolder(CString strFullName)
{
	LIST_VIEW*	pListView;
	CFileFind	ff;

	if (m_pFileList != NULL)
		RemoveAllFileList();

	m_pFileList = new CObList;

	SetCurrentPath(strFullName);
	strFullName += "*.*";

	if (ff.FindFile(strFullName) == TRUE)
	{
		BOOL	bFlag = TRUE;
		while(bFlag == TRUE)
		{
			bFlag = ff.FindNextFile();

			if (ff.IsDirectory() || ff.IsDots())
				continue;

			pListView = new LIST_VIEW;
			InitListViewStruct(pListView);

			pListView->strName = ff.GetFileName();
			pListView->strPath = ff.GetFilePath();

			//if (ff.IsDirectory() == TRUE)
			{
				//pListView->bIsDirectory = TRUE;//strFolderList->Add(ff.GetFileName());
				//pListView->strKind = "파일 폴더";
			}
			//else
			{
				CString		strName = pListView->strName;
				CString		strExt = ff.GetFileTitle();

				int			nNum = strName.GetLength() - strExt.GetLength();

				if (nNum == 0)
					strExt = "";
				else
					strExt = strName.Right(nNum - 1);
				pListView->strKind = strExt + " 파일";
			}
			pListView->dwFileSize = ff.GetLength();

			CTime	time;
			if (ff.GetCreationTime(time) == TRUE)
				pListView->tCreateTime = time;
			if (ff.GetLastAccessTime(time) == TRUE)
				pListView->tLastAccessTime = time;
			if (ff.GetLastWriteTime(time) == TRUE)
				pListView->tLastWriteTime = time;
			if (ff.IsHidden() == TRUE)
				pListView->bIsHidden = TRUE;
			if (ff.IsReadOnly() == TRUE)
				pListView->bIsReadOnly = TRUE;
			if (ff.IsArchived() == TRUE)
				pListView->bIsArchived = TRUE;
			if (ff.IsSystem() == TRUE)
				pListView->bIsSystem = TRUE;

			m_pFileList->AddTail((CObject*)pListView);
		}
	}
	ff.Close();

	m_pExpListView->SetFileList();
}

CObList* CExplorerTestDoc::GetFileList()
{
	return m_pFileList;
}

CString CExplorerTestDoc::GetCurrentPath()
{
	return m_strCurrentPath;
}

BOOL CExplorerTestDoc::DeleteReadOnlyFile(CString strPath)
{
	CFileStatus		fs;

	if (CFile::GetStatus(strPath, fs) == TRUE)
	{
		fs.m_attribute = 0x00;	// Normal한 파일로 파꾼다.
		CFile::SetStatus(strPath, fs);

		if (::DeleteFile(strPath) == FALSE)
		{
			return	FALSE;
		}
	}
	else
	{
		return	FALSE;
	}

	return	TRUE;
}

// Drag & Drop Data
void CExplorerTestDoc::SetCopyFileList(CObList* pFileList)
{
	LIST_VIEW*	pListView;

	m_copyFileList.RemoveAll();

	for(POSITION pos = pFileList->GetHeadPosition() ; pos != NULL ; )
	{
		pListView = (LIST_VIEW*)pFileList->GetNext(pos);
		m_copyFileList.AddTail((CObject*)pListView);
	}
}

void CExplorerTestDoc::SerializeCopyFiles(CArchive& ar)
{
	int			nCount;
	LIST_VIEW*	pListView;

	if (ar.IsStoring())
	{
		nCount = m_copyFileList.GetCount();

		ar << nCount;

		//for(int i = 0 ; i < nCount ; i++)
		for(POSITION pos = m_copyFileList.GetHeadPosition() ; pos != NULL ; )
		{
			pListView = (LIST_VIEW*)m_copyFileList.GetNext(pos);
			ar << (LONG)pListView;
		}
	}
	else
	{
		LONG	fileValue;

		m_copyFileList.RemoveAll();
		ar >> nCount;

		for(int i = 0 ; i < nCount ; i++)
		{
			ar >> fileValue;
			m_copyFileList.AddTail((CObject*)(LIST_VIEW*)fileValue);
		}
	}
}

CObList* CExplorerTestDoc::GetCopyFileList()
{
	return	&m_copyFileList;
}

/////////////////////////////////////////////////////////////////////////////
// CExplorerTestDoc private functions

void CExplorerTestDoc::RemoveAllFileList()
{
	LIST_VIEW*	pListView;

	for( POSITION pos = m_pFileList->GetHeadPosition() ; pos != NULL ; )
	{
		pListView = (LIST_VIEW*)m_pFileList->GetNext(pos);
		delete	pListView;
	}

	m_pFileList->RemoveAll();
	delete	m_pFileList;
	m_pFileList = NULL;
}

void CExplorerTestDoc::SetCurrentPath(CString strCurrentPath)
{
	m_strCurrentPath = strCurrentPath;
}

void CExplorerTestDoc::InitListViewStruct(LIST_VIEW* pListView)
{
	pListView->strName = "";
	pListView->strPath = "";
	//pListView->bIsDirectory = FALSE;
	pListView->dwFileSize = 0;
	pListView->strKind = "";
	pListView->tCreateTime = 0;
	pListView->tLastAccessTime = 0;
	pListView->tLastWriteTime = 0;
	pListView->bIsHidden = FALSE;
	pListView->bIsReadOnly = FALSE;
	pListView->bIsArchived = FALSE;
	pListView->bIsSystem = FALSE;
}
