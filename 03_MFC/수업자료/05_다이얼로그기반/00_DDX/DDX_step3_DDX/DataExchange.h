#if !defined(_CDATAEXCHANGE_DEFINED_)
#define _CDATAEXCHANGE_DEFINED_

#include "CWnd.h"

/*
 DDX : �ؽ�Ʈ �ڽ� ��Ʈ�Ѱ� ��Ʈ�ѿ� ������ ��� ���� �ڵ� �ڵ�ȭ
 - DoDataExchange()
 - UpdateData()
 - DDX_  �����Լ� 

 DDX�� ���� 
 - ����ڴ� ���̾�α� ������ ��ȯ�� ���� updateData()ȣ��
 - ���̾�α� Ŭ������ ���̽� Ŭ������ CDialog UpdateData()��
   ���� �Լ� DoDataExchange()�� ȣ��
 - ����ڴ� ��ȯ�� ���ϴ� �����͸�, ��ӹ��� DoDataExchange()
   �Լ��� ���� 
*/



/*
������ ��ȯ�� ���� ������ �����ϴ� Ŭ���� ����
*/

class CDataExchange
{
// Attributes
public:

	// TRUE => ��Ʈ���� ���� �ɹ� ������ ���� 
    BOOL m_bSaveAndValidate;   

	// ������ ��ȯ�ϴ� ������ ��ü  
    CWnd* m_pDlgWnd;           

    /*
// Operations (for implementors of DDX and DDV procs)
    HWND PrepareCtrl(int nIDC);     // return HWND of control
    HWND PrepareEditCtrl(int nIDC); // return HWND of control
    void Fail();                    // will throw exception

#ifndef _AFX_NO_OCC_SUPPORT
    CWnd* PrepareOleCtrl(int nIDC); // for OLE controls in dialog
#endif
    */


	// ������ 
    CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate);
    /*
    HWND m_hWndLastControl;    // last control used (for validation)
    BOOL m_bEditLastControl;   // last control was an edit item
    */
};//class CDataExchange

#endif // !defined(_CDATAEXCHANGE_DEFINED_)
