#include "stdafx.h"
#include "Dialog.h"
#include "CWinApp.h"

extern CWinApp app;

// Dialog Procedure --------------------------------------
int CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);


HWND     CDialog::m_hDlg         = NULL; // dialog window handle
CDialog* CDialog::m_pDlgObject   = NULL; // dialog object pointer


/*static*/ CDialog* CDialog::GetDialogFromHandle(HWND hDlg)
{
    m_hDlg = hDlg;
    return m_pDlgObject;
}


CDialog::CDialog(CDialog* pDlgObject)
{
    m_pDlgObject = pDlgObject;     // pointer to a dialog object
}

CDialog::~CDialog()
{
}

/*virtual*/ void CDialog::DoDataExchange(CDataExchange* pDX)
{
}//CDialog::DoDataExchange()

int CDialog::UpdateData(int bSaveAndValidate /*= 1*/)
{
    CDataExchange dx(bSaveAndValidate);
    
    DoDataExchange(&dx);
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
        }
        ++i;
    }

    return FALSE;
}
