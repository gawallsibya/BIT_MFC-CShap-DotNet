/*
// �����Լ��� MFC�� ����Ǵ� ���

  ex) 

1. ����ڰ� ������ ������ �� �ֵ��� ���� ���̾�α� ���
2. ����ڰ� ������ �����ϸ� ������̾�α� �����ϰ� ���õ� ���� ����
3. ���� ���Ŀ� ���� �����͸� ������ �о�鿩 �޸𸮿� �ε�
4. ���µ� ������ �ݴ´�.
==> ���� ó���ص� ���� ��ƾ��??>

*/


class CMFCOpen
{
public:
	void			FileOpen();
	char *			GetFileName();
	virtual void	Read();
	//.. ��Ÿ �Լ�...
};


void MFCOpen::Read()
{
	// �ƹ� ó���� ���� ����
}

char* CMFCOpen::GetFileName()
{
	// ���� ���̾�α׸� ����ϰ�
	// ����ڰ� ������ ���ϸ� ����
}

void CMFCOpen::FileOpen()
{
	char *strFileName;
	strFileName = GetFileName();

	//... ���� ����

	Read();// ���� ������ �дºκ�

	//......���� �ݱ� 
}





///////////////////// MFC �� �⺻���� �����ϴ� �ڵ�



void main()
{
	CMyOpen myDoc;
	myDoc.FileOpen();
}


////////////////////// ���α׷��Ӱ� �ۼ��ϴ� �κ�
class CMyOpen :: public MFCOpen
{
	public:
	virtual void Read();
};

void CMyOpen::Read()
{
	// ���α׷��ӿ��� �ʿ��� ���� ó���� �Ѵ�.
}