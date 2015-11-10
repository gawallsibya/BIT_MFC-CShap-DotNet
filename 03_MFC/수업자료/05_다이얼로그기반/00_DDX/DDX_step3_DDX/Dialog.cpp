#include "stdafx.h"
#include "Dialog.h"
#include "CWinApp.h"

extern CWinApp app;

// Dialog Procedure --------------------------------------
int CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

CDialog* CDialog::m_pDlgObject = NULL; // dialog object pointer

/*static*/ CDialog* CDialog::GetDialogFromHandle(HWND hDlg)
{
    m_pDlgObject->m_hwnd = hDlg;
    return m_pDlgObject;
}//CDialog::GetDialogFromHandle()


CDialog::CDialog(CDialog* pDlgObject)
{
    m_pDlgObject = pDlgObject;     // pointer to a dialog object
}//CDialog::CDialog()


CDialog::~CDialog()
{
}//CDialog::~CDialog()



/*virtual*/ void CDialog::DoDataExchange(CDataExchange* pDX)
{
}



int CDialog::UpdateData(int bSaveAndValidate /*= 1*/)
{
	// 객체 생성 
    CDataExchange dx(this, bSaveAndValidate);
    
	// 함수 호출 
    DoDataExchange(&dx);		// 가상 함수 
    return 1;
}


int CDialog::DoModal()
{
    return DialogBox(
        app.GetInstanceHandle(),        // application instance handle
        "AboutBox",                     // actually IDD will be used
        app.GetMainWnd()->GetSafeHwnd(),// parent window handle
        DlgProc );                      // dialog procedure
}



//{{ seojt: 2003-11-12 오전 11:01:39
// MFC에서는 모든 데이터 타입에 대한 DDX_함수를 제공한다. 
void DDX_Text(CDataExchange* pDX, UINT id, char* str)
{
    if ( pDX->m_bSaveAndValidate )
    {
        GetDlgItemText(pDX->m_pDlgWnd->GetSafeHwnd(), id, str, 19);
    }
    else
    {
        SetDlgItemText(pDX->m_pDlgWnd->GetSafeHwnd(), id, str);
    }
}
//}} seojt




//Dialog Window procedure-----------------------------------------
int CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) 
{
    int                     i = 0;
    CCmdTarget*             pDialogWnd;
    const MessageMap*       pMessageMap;

    pDialogWnd  = CDialog::GetDialogFromHandle(hDlg);
    pMessageMap = pDialogWnd->GetMessageMap();

    while ( 0 != pMessageMap[i].iMsg )
    {
        if ( LOWORD(iMsg) == pMessageMap[i].iMsg )
        {
            (pDialogWnd->*pMessageMap[i].fp)(wParam, lParam);
            return TRUE;
        }//if
        ++i;
    }//while

    return FALSE;
}//DlgProc()
