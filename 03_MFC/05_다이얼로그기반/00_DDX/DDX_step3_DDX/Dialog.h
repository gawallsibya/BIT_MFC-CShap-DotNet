#if !defined(_CDIALOG_DEFINED_)
#define _CDIALOG_DEFINED_

#include "CObject.h"
#include "DataExchange.h"
#include "CWnd.h"

//{{ seojt: 2003-11-12 오전 11:00:23
void DDX_Text(CDataExchange* pDX, UINT id, char* str);
//}} seojt

class CDialog : public CWnd
{
public:
    static CDialog* m_pDlgObject; // real dialog object pointer
    static CDialog* GetDialogFromHandle(HWND hDlg);

    CDialog(CDialog* pDlgObject);
    virtual ~CDialog();

    int UpdateData(int bSaveAndValidate = 1);
    int DoModal();

protected:

	// 가상함수 
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
};

#endif // !defined(_CDIALOG_DEFINED_)
