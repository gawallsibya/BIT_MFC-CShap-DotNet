// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExplorerTest.h"
#include "InfoDlg.h"
//
#include "data.h"
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog


CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfoDlg)
	m_bArchive = FALSE;
	m_bHidden = FALSE;
	m_bReadOnly = FALSE;
	m_bSystem = FALSE;
	m_strCreationTime = _T("");
	m_strFileName = _T("");
	m_strFileSize = _T("");
	m_strKind = _T("");
	m_strLastAccessTime = _T("");
	m_strLastWriteTime = _T("");
	m_strName = _T("");
	m_strPath = _T("");
	//}}AFX_DATA_INIT
}


void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
	DDX_Check(pDX, IDC_CHECK_ARCHIVE, m_bArchive);
	DDX_Check(pDX, IDC_CHECK_HIDDEN, m_bHidden);
	DDX_Check(pDX, IDC_CHECK_READONLY, m_bReadOnly);
	DDX_Check(pDX, IDC_CHECK_SYSTEM, m_bSystem);
	DDX_Text(pDX, IDC_CREATION, m_strCreationTime);
	DDX_Text(pDX, IDC_FILE_NAME, m_strFileName);
	DDX_Text(pDX, IDC_FILESIZE, m_strFileSize);
	DDX_Text(pDX, IDC_KIND, m_strKind);
	DDX_Text(pDX, IDC_LAST_ACCESS, m_strLastAccessTime);
	DDX_Text(pDX, IDC_LAST_WRITE, m_strLastWriteTime);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_POSITION, m_strPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg public functions

void CInfoDlg::SetInfo(CObList* pFileList)
{
	CString		temp;
	CTime		tTime;
	BOOL		bOnce = FALSE;
	DWORD		dwSize = 0;
	LIST_VIEW*	pListInfo;
	int			nCount = pFileList->GetCount();

	for(POSITION pos = pFileList->GetHeadPosition() ; pos != NULL ; )
	{
		pListInfo = (LIST_VIEW*)pFileList->GetNext(pos);

		if (bOnce == FALSE)
		{
			CString		str = pListInfo->strName;
			m_strPath = pListInfo->strPath;
			m_strPath = m_strPath.Left(m_strPath.GetLength() - str.GetLength());
			bOnce = TRUE;
		}

		if (nCount == 1)	// 파일이 한 개만 선택되어진 경우
		{
			m_strName = pListInfo->strName;
			m_strKind = pListInfo->strKind;

			temp.Format("%d 바이트", pListInfo->dwFileSize);
			m_strFileSize = temp;
			m_strFileName = m_strName;
			tTime = pListInfo->tCreateTime;

			if (tTime == 0)
				m_strCreationTime = "(알 수 없음)";
			else
			{
				m_strCreationTime.Format("%d년 %d월 %d일 %d:%d:%d",
					tTime.GetYear(), tTime.GetMonth(), tTime.GetDay(),
					tTime.GetHour(), tTime.GetMinute(), tTime.GetSecond());
			}

			tTime = pListInfo->tLastWriteTime;

			if (tTime == 0)
				m_strLastWriteTime = "(알 수 없음)";
			else
			{
				m_strLastWriteTime.Format("%d년 %d월 %d일 %d:%d:%d",
					tTime.GetYear(), tTime.GetMonth(), tTime.GetDay(),
					tTime.GetHour(), tTime.GetMinute(), tTime.GetSecond());
			}

			tTime = pListInfo->tLastAccessTime;

			if (tTime == 0)
				m_strLastAccessTime = "(알 수 없음)";
			else
			{
				m_strLastAccessTime.Format("%d년 %d월 %d일",
					tTime.GetYear(), tTime.GetMonth(), tTime.GetDay());
			}

			m_bReadOnly = pListInfo->bIsReadOnly;
			m_bHidden = pListInfo->bIsHidden;
			m_bArchive = pListInfo->bIsArchived;
			m_bSystem = pListInfo->bIsSystem;

			break;
		}
		else	// 여러개가 선택된 경우...
		{
			dwSize += pListInfo->dwFileSize;

			m_bReadOnly = pListInfo->bIsReadOnly ? TRUE : FALSE;
			m_bHidden = pListInfo->bIsHidden ? TRUE : FALSE;
			m_bArchive = pListInfo->bIsArchived ? TRUE : FALSE;
			m_bSystem = pListInfo->bIsSystem ? TRUE : FALSE;
		}
	}
	
	if (nCount > 1)
	{
		m_strName.Format("파일 %d", nCount);
		m_strKind = "복수 종류";
		temp.Format("%d bytes", dwSize);
		m_strFileSize = temp;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

HBRUSH CInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(0,0,255));
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
