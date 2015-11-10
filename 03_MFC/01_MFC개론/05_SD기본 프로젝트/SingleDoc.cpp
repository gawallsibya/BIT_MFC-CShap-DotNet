// SingleDoc.cpp : implementation of the CSingleDoc class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc

IMPLEMENT_DYNCREATE(CSingleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDoc, CDocument)
	//{{AFX_MSG_MAP(CSingleDoc)
	ON_COMMAND(ID_TEST, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc construction/destruction

CSingleDoc::CSingleDoc()
{
	// TODO: add one-time construction code here

}

CSingleDoc::~CSingleDoc()
{
}

BOOL CSingleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSingleDoc serialization

void CSingleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc diagnostics

#ifdef _DEBUG
void CSingleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc commands

void CSingleDoc::OnTest() 
{
	// TODO: Add your command handler code here
	
}
