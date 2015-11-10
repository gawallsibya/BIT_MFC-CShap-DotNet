// MyExplorerDoc.cpp : implementation of the CMyExplorerDoc class
//

#include "stdafx.h"
#include "MyExplorer.h"

#include "MyExplorerDoc.h"
#include "CntrItem.h"

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

}

CMyExplorerDoc::~CMyExplorerDoc()
{
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
