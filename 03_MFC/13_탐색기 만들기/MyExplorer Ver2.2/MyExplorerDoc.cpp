// MyExplorerDoc.cpp : implementation of the CMyExplorerDoc class
//

#include "stdafx.h"
#include "MyExplorer.h"

#include "MyExplorerDoc.h"
#include "CntrItem.h"

#include "MyExplorerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerDoc

IMPLEMENT_DYNCREATE(CMyExplorerDoc, COleDocument)

BEGIN_MESSAGE_MAP(CMyExplorerDoc, COleDocument)
	//{{AFX_MSG_MAP(CMyExplorerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
// CMyExplorerDoc construction/destruction

CMyExplorerDoc::CMyExplorerDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here
	m_pFileList = NULL;
}

CMyExplorerDoc::~CMyExplorerDoc()
{
	if( m_pFileList != NULL)
		RemoveAllFileList();
}

BOOL CMyExplorerDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyExplorerDoc serialization

void CMyExplorerDoc::Serialize(CArchive& ar)
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
// CMyExplorerDoc diagnostics

#ifdef _DEBUG
void CMyExplorerDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CMyExplorerDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyExplorerDoc commands

void CMyExplorerDoc::GetChildFolders(CStringArray *strFolderList, CString strParentFolder)
{
	// MFC에서 지원되는 파일 검색 객체 
	CFileFind	ff;

	if (strParentFolder.Right(1) != '\\')
	{
		strParentFolder += '\\';
	}

	strParentFolder += "*.*";

	// 주어진 경로의 파일을 찾음 
	if (ff.FindFile(strParentFolder) == TRUE)
	{
		BOOL	bFlag = TRUE;
		while(bFlag == TRUE)
		{
			// 파일이 존재할 경우 다음 파일을 찾을수 
			// 있도록 해준다.
			bFlag = ff.FindNextFile();
			// 파일이 디렉토리이면 0이 아닌 수를 리턴
			// 파일이 '.' 또는 '..'이면 0이 아닌 수를 리턴
			if (ff.IsDirectory() && !ff.IsDots())
				strFolderList->Add(ff.GetFileName());
		}
	}
	ff.Close();
}

//------------------------------------------------
// 파일의 리스트 및 각 파일에 대한 자세한 정보를 
// 함께 저장하게 됨
// data.h파일에 해당 구조체를 선언한다.
//--------------------------------------------------
void CMyExplorerDoc::SelectTreeViewFolder(CString strFullName)
{

	LIST_VIEW*	pListView;
	CFileFind	ff;

	// 사용자가 폴더를 선택할 때마다 파일 리스트를
	// 새로 업데이트 해야 함
	// 따라서 기존 정보를 모두 삭제한다.
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

			// 디렉토리 , 도트파일이면 다시 찾음 
			if (ff.IsDirectory() || ff.IsDots())
				continue;
			
			// 파일 정보를 알아내서LIST_VIEW 구조체에 
			// 저장한 후 
			// 그것을 모두 m_pFileList에 저장한다.
			pListView = new LIST_VIEW;
			InitListViewStruct(pListView);

			pListView->strName = ff.GetFileName();
			pListView->strPath = ff.GetFilePath();

			CString		strName = pListView->strName;
			CString		strExt = ff.GetFileTitle();

			int			nNum = strName.GetLength() - strExt.GetLength();

			if (nNum == 0)
				strExt = "";
			else
				strExt = strName.Right(nNum - 1);
			pListView->strKind = strExt + " 파일";
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

	//------------------------------
	m_pExpListView->SetFileList();
	//-------------------------------------
}

void CMyExplorerDoc::InitListViewStruct(LIST_VIEW *pListView)
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

void CMyExplorerDoc::RemoveAllFileList()
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

	//소멸자도 처리  
}

void CMyExplorerDoc::SetCurrentPath(CString strCurrentPath)
{
	m_strCurrentPath = strCurrentPath;
}
