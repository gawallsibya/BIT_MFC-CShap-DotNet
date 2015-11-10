// HelloDoc.cpp : implementation of the CHelloDoc class
//

#include "stdafx.h"
#include "MultiDoc.h"

#include "HelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc
#define BLACK	RGB(0x00, 0x00, 0x00)
#define RED		RGB(0xff, 0x00, 0x00)
#define GREEN	RGB(0x00, 0xff, 0x00)
#define BLUE	RGB(0x00, 0x00, 0xff)

IMPLEMENT_DYNCREATE(CHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CHelloDoc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc construction/destruction

CHelloDoc::CHelloDoc()
{
	// TODO: add one-time construction code here

}

CHelloDoc::~CHelloDoc()
{
}

BOOL CHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_ptLoc = CPoint(0, 0);
	m_curColor = BLACK;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc serialization

void CHelloDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_ptLoc << m_curColor;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_ptLoc >> m_curColor;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc diagnostics

#ifdef _DEBUG
void CHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHelloDoc commands

CPoint CHelloDoc::GetLocation()
{
	return m_ptLoc;
}

void CHelloDoc::SetLocation(CPoint pt)
{
	m_ptLoc = pt;
	UpdateAllViews(NULL);
}

COLORREF CHelloDoc::GetColor()
{
	return m_curColor;
}

void CHelloDoc::SetColor(COLORREF color)
{
	m_curColor = color;
	UpdateAllViews(NULL);
}

void CHelloDoc::OnColorBlack() 
{
	// TODO: Add your command handler code here
	SetColor(BLACK);
}

void CHelloDoc::OnColorRed() 
{
	// TODO: Add your command handler code here
	SetColor(RED);
}

void CHelloDoc::OnColorGreen() 
{
	// TODO: Add your command handler code here
	SetColor(GREEN);
}

void CHelloDoc::OnColorBlue() 
{
	// TODO: Add your command handler code here
	SetColor(BLUE);
}
