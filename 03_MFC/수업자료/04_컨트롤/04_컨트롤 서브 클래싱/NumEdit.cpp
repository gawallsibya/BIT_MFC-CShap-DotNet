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
	// �����ϰ�츸 �θ𿡰� ����. ������ ����� ����Ѵ�.	

	if ( ( nChar >= '0' && nChar <= '9' ) || nChar == 8) // bs key
		CEdit::OnChar(nChar, nRepCnt, nFlags);

	// �׿��� ���ڴ� �ƹ� �ϵ� ���� �ʴ´�.
}

















