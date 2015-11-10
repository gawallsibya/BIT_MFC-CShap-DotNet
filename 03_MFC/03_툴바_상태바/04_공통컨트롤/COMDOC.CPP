// ComDoc.cpp : implementation of the CComDlgDoc class
//

#include "stdafx.h"
#include "ComDlg.h"

#include "ComDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComDlgDoc

IMPLEMENT_DYNCREATE(CComDlgDoc, CDocument)

BEGIN_MESSAGE_MAP(CComDlgDoc, CDocument)
	//{{AFX_MSG_MAP(CComDlgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComDlgDoc construction/destruction

CComDlgDoc::CComDlgDoc()
{
	// TODO: add one-time construction code here

}

CComDlgDoc::~CComDlgDoc()
{
}

BOOL CComDlgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CComDlgDoc serialization

void CComDlgDoc::Serialize(CArchive& ar)
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
// CComDlgDoc diagnostics

#ifdef _DEBUG
void CComDlgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComDlgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComDlgDoc commands
