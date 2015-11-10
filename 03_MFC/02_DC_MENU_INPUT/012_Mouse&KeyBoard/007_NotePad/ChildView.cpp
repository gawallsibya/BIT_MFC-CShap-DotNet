// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "NotePad.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CEdit )
	//{{AFX_MSG_MAP(CChildView)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (! CEdit::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;

	return TRUE;
}


void CChildView::OnEditCopy() 
{
	Copy();
}
void CChildView::OnEditCut() 
{
	Cut();
}
void CChildView::OnEditPaste() 
{
	Paste();
}
void CChildView::OnEditUndo() 
{	
	Undo();
}










void CChildView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	int start, end;
	GetSel( start, end); // 선택된 내용이 없다면 start == end
	pCmdUI->Enable( start != end );
}         
void CChildView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	int start, end;
	GetSel( start, end);
	pCmdUI->Enable( start != end );
}
void CChildView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	// 클립 보드에 text가 있는지 조사.
	BOOL b = IsClipboardFormatAvailable( CF_TEXT );
	pCmdUI->Enable( b );
}
void CChildView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( CanUndo() );	
}



