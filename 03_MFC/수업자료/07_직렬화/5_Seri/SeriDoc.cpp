// SeriDoc.cpp : implementation of the CSeriDoc class
//

#include "stdafx.h"
#include "Seri.h"

#include "SeriDoc.h"
#include "Data.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeriDoc

IMPLEMENT_DYNCREATE(CSeriDoc, CDocument)

BEGIN_MESSAGE_MAP(CSeriDoc, CDocument)
	//{{AFX_MSG_MAP(CSeriDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeriDoc construction/destruction

CSeriDoc::CSeriDoc()
{
	// TODO: add one-time construction code here

}

CSeriDoc::~CSeriDoc()
{
}

BOOL CSeriDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSeriDoc serialization

void CSeriDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_List.GetCount();
		for(POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
			m_List.GetNext(pos)->Serialize(ar);
	}
	else
	{
		m_List.RemoveAll();
		// TODO: add loading code here
		int nCount;
		CData *pData;

		ar >> nCount;
		for(int i=0; i<nCount; i++)
		{
			pData = new CData;
			pData->Serialize(ar);
			m_List.AddTail(pData);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSeriDoc diagnostics

#ifdef _DEBUG
void CSeriDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSeriDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSeriDoc commands
