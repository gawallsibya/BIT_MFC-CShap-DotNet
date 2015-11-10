// NumEdit.cpp : implementation file
//

#include "stdafx.h"
#include "SubClass.h"
#include "NumEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumEdit

CNumEdit::CNumEdit()
{
}

CNumEdit::~CNumEdit()
{
}


BEGIN_MESSAGE_MAP(CNumEdit, CEdit)
	//{{AFX_MSG_MAP(CNumEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumEdit message handlers

void CNumEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 숫자일경우만 부모에게 전달. 원래의 기능을 사용한다.	

	if ( ( nChar >= '0' && nChar <= '9' ) || nChar == 8) // bs key
		CEdit::OnChar(nChar, nRepCnt, nFlags);

	// 그외의 문자는 아무 일도 하지 않는다.
}

















