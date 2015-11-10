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
	// MFC���� �����Ǵ� ���� �˻� ��ü 
	CFileFind	ff;

	if (strParentFolder.Right(1) != '\\')
	{
		strParentFolder += '\\';
	}

	strParentFolder += "*.*";

	// �־��� ����� ������ ã�� 
	if (ff.FindFile(strParentFolder) == TRUE)
	{
		BOOL	bFlag = TRUE;
		while(bFlag == TRUE)
		{
			// ������ ������ ��� ���� ������ ã���� 
			// �ֵ��� ���ش�.
			bFlag = ff.FindNextFile();
			// ������ ���丮�̸� 0�� �ƴ� ���� ����
			// ������ '.' �Ǵ� '..'�̸� 0�� �ƴ� ���� ����
			if (ff.IsDirectory() && !ff.IsDots())
				strFolderList->Add(ff.GetFileName());
		}
	}
	ff.Close();
}

//------------------------------------------------
// ������ ����Ʈ �� �� ���Ͽ� ���� �ڼ��� ������ 
// �Բ� �����ϰ� ��
// data.h���Ͽ� �ش� ����ü�� �����Ѵ�.
//--------------------------------------------------
void CMyExplorerDoc::SelectTreeViewFolder(CString strFullName)
{

	LIST_VIEW*	pListView;
	CFileFind	ff;

	// ����ڰ� ������ ������ ������ ���� ����Ʈ��
	// ���� ������Ʈ �ؾ� ��
	// ���� ���� ������ ��� �����Ѵ�.
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

			// ���丮 , ��Ʈ�����̸� �ٽ� ã�� 
			if (ff.IsDirectory() || ff.IsDots())
				continue;
			
			// ���� ������ �˾Ƴ���LIST_VIEW ����ü�� 
			// ������ �� 
			// �װ��� ��� m_pFileList�� �����Ѵ�.
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
			pListView->strKind = strExt + " ����";
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

	//�Ҹ��ڵ� ó��  
}

void CMyExplorerDoc::SetCurrentPath(CString strCurrentPath)
{
	m_strCurrentPath = strCurrentPath;
}
