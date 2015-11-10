// DirDoc.cpp : implementation of the CDirDoc class
//

#include "stdafx.h"
#include "Dir.h"

#include "DirDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDirDoc

IMPLEMENT_DYNCREATE(CDirDoc, CDocument)

BEGIN_MESSAGE_MAP(CDirDoc, CDocument)
	//{{AFX_MSG_MAP(CDirDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirDoc construction/destruction

CDirDoc::CDirDoc()
{
	// TODO: add one-time construction code here

}

CDirDoc::~CDirDoc()
{
}

BOOL CDirDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDirDoc serialization

void CDirDoc::Serialize(CArchive& ar)
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
// CDirDoc diagnostics

#ifdef _DEBUG
void CDirDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDirDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDirDoc commands
