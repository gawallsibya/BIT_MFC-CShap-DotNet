////////////////////////////////////////////////////////////
//	data.h

#ifndef	_DATA_H_
#define	_DATA_H_

// Drag & Drop 을 위한 문자열 정의
static	const	TCHAR	*FORMAT_FILECOPY = "FormatFileCopy";

// 파일 또는 폴더의 속성을 저장하는 구조체
typedef	struct	_LIST_VIEW
{
	CString		strName;			// 이름
	CString		strPath;			// 경로
	//BOOL		bIsDirectory;		// 디렉토리
	DWORD		dwFileSize;			// 파일 크기
	CString		strKind;			// 파일 종류
	CTime		tCreateTime;		// 만든 날짜
	CTime		tLastAccessTime;	// 사용한 날짜
	CTime		tLastWriteTime;		// 바뀐 날짜
	BOOL		bIsHidden;			// hidden 파일
	BOOL		bIsReadOnly;		// 읽기 전용 파일
	BOOL		bIsArchived;		// 기록 파일
	BOOL		bIsSystem;			// 시스템 파일
}LIST_VIEW;

#endif	// _DATA_H_
