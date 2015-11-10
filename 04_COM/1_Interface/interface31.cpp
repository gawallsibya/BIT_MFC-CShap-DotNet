//------------------------------------------------------------------
// COM �������̽� ���� : ���� ī���� 
//------------------------------------------------------------------

/*
  [ �⺻ ���� ]
  1. Ŭ���̾�Ʈ�� ������ �ִ� ������Ʈ�� ���� ������ ������ �������̽�
     ���� ��� �� �� ����.
  2. ���� ������Ʈ�� ������ ������ ������ �� �ִ� ����� �����Ѵ�.

  3. ������Ʈ�� 
     Ŭ���̾�Ʈ�� ���ؼ� �������̽� ����� �䱸�� ��� 
     Ŭ���̾�Ʈ�� ���ؼ� �Τ����̽� ����� ������ ��� ������ �� �� �ִ�. 

  4. �̷��� ������ �������� AddRef �� Relase �Լ��� ������ �����Ѵ�.

  [ ���� ī���� ��Ģ ]
  1. AddRef : ���� ī��Ʈ ���� 
     Relase : ���� ī��Ʈ ����
	 0 �� ���  �޸� ���� 

  2. �����ϱ� ���� AddRef �� ȣ�� 
     - �������̽��� �����ϴ� �Լ��� �׻� �����ϱ� ����  �����Ϳ� ���� AddRef�� ȣ��
	   QueryInterface(), CreateInstance()�� ���ԵǾ� �ִ�.
	   ���� ���� �Լ��� ���� �������̽��� ���� �Ŀ��� AddRef�� ȣ���� �ʿ� ����.
  3. �۾��� ��ģ �Ŀ��� AddRef�� ȣ��
   
  4. �Ҵ��� �Ŀ� AddRef�� ȣ�� 
     - �ٸ� �������̽� �����Ϳ� ���� �������̽��� �����͸� �Ҵ��Ͽ��ٸ� AddRef�� ȣ�� 
	   ��ü ������ ī��Ʈ ���� �ʿ� 

  5. ������ �������̽��� ���� ����ī��Ʈ�� �����Ѵ�.

*/



// ���� 1
/*
void main()
{
	// ���ο� ������Ʈ ���� 
	IUnknown* pIUnknown = CreateInstance();

	// interface ��� 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// �������̽� ���
		pIX->Release();		
	}
	pIUnknown->Release();
}
*/

// ���� 2
/*
void main()
{
	// ���ο� ������Ʈ ���� 
	IUnknown* pIUnknown = CreateInstance();

	// interface ��� 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

	pIUnknown->Release();

	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// �������̽� ���
		pIX->Release();		
	}
//	pIUnknown->Release();
}
// �� �̻� �ʿ���� �������̽��� �ٷ� Release ���� 
*/


// ���� 3
/*
void main()
{
	// ���ο� ������Ʈ ���� 
	IUnknown* pIUnknown = CreateInstance();

	// interface ��� 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	pIUnknown->Release();

	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// �������̽� ���
		IX *pIX2 = pIX;

		pIX2->AddRef();		// ����� ���� ī��Ʈ ���� 
		pIX2->Fx();

		pIX2->Release();	// ���� 
		pIX->Release();		
	}
//	pIUnknown->Release();
}
// ���� ������ pIX2->AddRef();	pIX2->Release();
// ȣ���� �ʿ��ұ�??  
*/