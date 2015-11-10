// MapDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CMap.h"
#include "MapDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapDialog dialog


CMapDialog::CMapDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMapDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMapDialog)
	m_editStr = _T("");
	m_listStr = _T("");
	//}}AFX_DATA_INIT
}


void CMapDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapDialog)
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Text(pDX, IDC_EDIT1, m_editStr);
	DDX_LBString(pDX, IDC_LIST1, m_listStr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMapDialog, CDialog)
	//{{AFX_MSG_MAP(CMapDialog)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapDialog message handlers

void CMapDialog::OnAdd() 
{
	UpdateData(TRUE);
	
	if(m_editStr.GetLength() > 0)
	{
		m_ctrlList.AddString(m_editStr);
		m_ctrlEdit.SetWindowText("");
	}
}

void CMapDialog::OnOK() 
{
	CString strItem;

	UpdateData(TRUE);
	//m_strSelected.Empty();

	for(int i=0; i<m_ctrlList.GetCount(); i++)
	{
		m_ctrlList.GetText(i, strItem);

		if(!m_strSelected[i].IsEmpty())
			m_strSelected[i] = _T(", ");

		m_strSelected[i] = strItem;
	}	
	
	CDialog::OnOK();
}
