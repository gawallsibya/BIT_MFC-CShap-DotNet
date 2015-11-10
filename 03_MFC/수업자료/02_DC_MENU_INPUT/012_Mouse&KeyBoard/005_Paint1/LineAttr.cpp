// LineAttr.cpp : implementation file
//

#include "stdafx.h"
#include "Paint1.h"
#include "LineAttr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineAttr dialog


CLineAttr::CLineAttr(CWnd* pParent /*=NULL*/)
	: CDialog(CLineAttr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineAttr)
	m_GColor = 0;
	m_BColor = 0;
	m_RColor = 0;
	m_PenWidth = 1;
	//}}AFX_DATA_INIT
}


void CLineAttr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineAttr)
	DDX_Text(pDX, IDC_EDIT_GCOLOR, m_GColor);
	DDX_Text(pDX, IDC_EDIT_BCOLOR, m_BColor);
	DDX_Text(pDX, IDC_EDIT_RCOLOR, m_RColor);
	DDX_Text(pDX, IDC_EDIT_WIDTHPEN, m_PenWidth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLineAttr, CDialog)
	//{{AFX_MSG_MAP(CLineAttr)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineAttr message handlers
