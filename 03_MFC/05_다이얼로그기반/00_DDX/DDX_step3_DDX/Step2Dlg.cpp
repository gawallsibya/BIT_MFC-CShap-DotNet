#include "stdafx.h"
#include <string.h>
#include "Step2Dlg.h"

#pragma warning(disable: 4355)
  // 'this' used in base member initialization list

BEGIN_MESSAGE_MAP(CStep2Dlg)
    { WM_INITDIALOG,  (CCmdTargetFunPointer)CStep2Dlg::OnInitDialog },
    { WM_COMMAND,     (CCmdTargetFunPointer)CStep2Dlg::OnCommand },
    { WM_LBUTTONDOWN, (CCmdTargetFunPointer)CStep2Dlg::OnLButtonDown },
END_MESSAGE_MAP()



CStep2Dlg::CStep2Dlg(CObject* pParent /*= NULL*/) : CDialog(this)
{
    //{{AFX_DATA_INIT(CStep4Dlg)
    strcpy(m_strEdit1, "");				//............
    //}}AFX_DATA_INIT
}



CStep2Dlg::~CStep2Dlg()
{
}



void CStep2Dlg::DoDataExchange(CDataExchange* pDX)
{
    //CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CStep2Dlg)
    DDX_Text(pDX, IDC_EDIT1, m_strEdit1);			//....함수 호출 
    //}}AFX_DATA_MAP
}

//----------------------------------------------------------------
// Name: OnInitDialog()
void CStep2Dlg::OnInitDialog(WPARAM wParam, LPARAM lParam)
{
    SetFocus( GetDlgItem(GetSafeHwnd(), IDC_EDIT1) );
    

    //SetDlgItemText(m_hDlg, IDC_EDIT1, m_strEdit1);

    UpdateData(FALSE);							//... 함수 호출 
}



void CStep2Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
    switch ( LOWORD(wParam) )
    {
    case IDOK:

        //GetDlgItemText(m_hDlg, IDC_EDIT1, m_strEdit1, 19);
        UpdateData(TRUE);					//... 함수 호출 

        EndDialog(GetSafeHwnd(), IDOK);
        break;
        
    case IDCANCEL:
        EndDialog(GetSafeHwnd(), IDCANCEL) ;
        break;
    }
}




void CStep2Dlg::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
    HWND hwnd = GetDlgItem(GetSafeHwnd(), IDOK);

    UpdateData(TRUE);
    SetWindowText(hwnd, m_strEdit1);
}

