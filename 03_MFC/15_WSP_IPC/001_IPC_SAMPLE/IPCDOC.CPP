// IPCDoc.cpp : implementation of the CIPCDoc class
//

#include "stdafx.h"
#include "IPC.h"

#include "IPCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPCDoc

IMPLEMENT_DYNCREATE(CIPCDoc, CDocument)

BEGIN_MESSAGE_MAP(CIPCDoc, CDocument)
	//{{AFX_MSG_MAP(CIPCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPCDoc construction/destruction

CIPCDoc::CIPCDoc()
{
	// TODO: add one-time construction code here

}

CIPCDoc::~CIPCDoc()
{
}

BOOL CIPCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CIPCDoc serialization

void CIPCDoc::Serialize(CArchive& ar)
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
// CIPCDoc diagnostics

#ifdef _DEBUG
void CIPCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIPCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIPCDoc commands
