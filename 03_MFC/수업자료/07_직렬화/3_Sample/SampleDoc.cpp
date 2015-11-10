// SampleDoc.cpp : implementation of the CSampleDoc class
//

#include "stdafx.h"
#include "Sample.h"

#include "SampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleDoc

IMPLEMENT_DYNCREATE(CSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSampleDoc, CDocument)
	//{{AFX_MSG_MAP(CSampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleDoc construction/destruction

CSampleDoc::CSampleDoc()
{
	// TODO: add one-time construction code here

}

CSampleDoc::~CSampleDoc()
{
}

// ID_FILE_NEW 메뉴를 누를때 호출된다.
BOOL CSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	buf.RemoveAll(); // 배열을 모두 지운다.
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSampleDoc serialization

void CSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// size 저장.
		ar << buf.GetSize();
		for (int i = 0 ;i < buf.GetSize(); i++)
			ar << buf[i];
	}
	else
	{
		int n;
		ar >> n; // 갯수 얻기.
		buf.RemoveAll();

		CRect r;
		for (int i = 0; i < n; i++)
		{
			ar >> r;
			buf.Add( r);
		}	
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSampleDoc diagnostics

#ifdef _DEBUG
void CSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSampleDoc commands
