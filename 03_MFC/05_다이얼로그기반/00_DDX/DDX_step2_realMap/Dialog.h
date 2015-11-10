#if !defined(_CDIALOG_DEFINED_)
#define _CDIALOG_DEFINED_

#include "CObject.h"
#include "DataExchange.h"
#include "CWnd.h"

class CDialog : public CWnd		// 1) CWnd 상속 
{
public:
    static HWND     m_hDlg;       // dialog window handle
    static CDialog* m_pDlgObject; // real dialog object pointer


    static CDialog* GetDialogFromHandle(HWND hDlg);// Dlg객체 리턴 

    CDialog(CDialog* pDlgObject);
    virtual ~CDialog();

    int UpdateData(int bSaveAndValidate = 1);

    int DoModal();									// ??

protected:
    //virtual function
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
};//class CDialog

#endif // !defined(_CDIALOG_DEFINED_)
/*
1) CDialog 역시 윈도우이므로 CWnd를 상속받는다.
 
2) 다이얼로그 객체를 리턴하는 함수 

3) 대화상자 출력 함수 
*/