/*
// 가상함수가 MFC에 적용되는 방식

  ex) 

1. 사용자가 파일을 선택할 수 있도록 열기 다이얼로그 출력
2. 사용자가 파일을 선택하면 열기다이얼로그 종료하고 선택된 파일 오픈
3. 파일 형식에 따라 데이터를 적절히 읽어들여 메모리에 로드
4. 오픈된 파일을 닫는다.
==> 누가 처리해도 동일 루틴은??>

*/


class CMFCOpen
{
public:
	void			FileOpen();
	char *			GetFileName();
	virtual void	Read();
	//.. 기타 함수...
};


void MFCOpen::Read()
{
	// 아무 처리를 하지 않음
}

char* CMFCOpen::GetFileName()
{
	// 열기 다이얼로그를 출력하고
	// 사용자가 선택한 파일명 리턴
}

void CMFCOpen::FileOpen()
{
	char *strFileName;
	strFileName = GetFileName();

	//... 파일 오픈

	Read();// 실제 파일을 읽는부분

	//......파일 닫기 
}





///////////////////// MFC 가 기본으로 제공하는 코드



void main()
{
	CMyOpen myDoc;
	myDoc.FileOpen();
}


////////////////////// 프로그래머가 작성하는 부분
class CMyOpen :: public MFCOpen
{
	public:
	virtual void Read();
};

void CMyOpen::Read()
{
	// 프로그래머에게 필요한 실제 처리를 한다.
}