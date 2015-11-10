// MOUSEECDoc.cpp : implementation of the CMOUSEECDoc class
//

#include "stdafx.h"
#include "MOUSEEC.h"

#include "MOUSEECDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECDoc

IMPLEMENT_DYNCREATE(CMOUSEECDoc, CDocument)

BEGIN_MESSAGE_MAP(CMOUSEECDoc, CDocument)
	//{{AFX_MSG_MAP(CMOUSEECDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECDoc construction/destruction

CMOUSEECDoc::CMOUSEECDoc()
{
	// TODO: add one-time construction code here

}

CMOUSEECDoc::~CMOUSEECDoc()
{
}

BOOL CMOUSEECDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMOUSEECDoc serialization

void CMOUSEECDoc::Serialize(CArchive& ar)
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
// CMOUSEECDoc diagnostics

#ifdef _DEBUG
void CMOUSEECDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMOUSEECDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECDoc commands
