//------------------------------------------------------------------
// COM 인터페이스 구현 : 참조 카운팅 
//------------------------------------------------------------------

/*
  [ 기본 이해 ]
  1. 클라이언트가 가지고 있는 컴포넌트에 대한 유일한 지식은 인터페이스
     수명 제어를 할 수 없다.
  2. 따라서 컴포넌트가 스스로 수명을 제어할 수 있는 방법을 이해한다.

  3. 컴포넌트는 
     클라이언트에 의해서 인터페이스 사용을 요구할 경우 
     클라이언트에 의해서 인ㅌ페이스 사용을 마쳤을 경우 시점을 알 수 있다. 

  4. 이러한 시점을 기준으로 AddRef 및 Relase 함수의 구현을 이해한다.

  [ 참조 카운팅 규칙 ]
  1. AddRef : 참조 카운트 증가 
     Relase : 참조 카운트 감소
	 0 일 경우  메모리 해제 

  2. 리턴하기 전에 AddRef 를 호출 
     - 인터페이스를 리턴하는 함수는 항상 리턴하기 전에  포인터에 대한 AddRef를 호출
	   QueryInterface(), CreateInstance()에 포함되어 있다.
	   따라서 위의 함수로 부터 인터페이스를 얻은 후에는 AddRef를 호출할 필요 없다.
  3. 작업을 마친 후에는 AddRef를 호출
   
  4. 할당한 후에 AddRef를 호출 
     - 다른 인터페이스 포인터에 대해 인터페이스의 포인터를 할당하였다면 AddRef를 호출 
	   자체 참조도 카운트 증가 필요 

  5. 각각의 인터페이스에 대해 참조카운트를 관리한다.

*/



// 예제 1
/*
void main()
{
	// 새로운 컴포넌트 생성 
	IUnknown* pIUnknown = CreateInstance();

	// interface 얻기 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// 인터페이스 사용
		pIX->Release();		
	}
	pIUnknown->Release();
}
*/

// 예제 2
/*
void main()
{
	// 새로운 컴포넌트 생성 
	IUnknown* pIUnknown = CreateInstance();

	// interface 얻기 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

	pIUnknown->Release();

	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// 인터페이스 사용
		pIX->Release();		
	}
//	pIUnknown->Release();
}
// 더 이상 필요없는 인터페이스는 바로 Release 가능 
*/


// 예제 3
/*
void main()
{
	// 새로운 컴포넌트 생성 
	IUnknown* pIUnknown = CreateInstance();

	// interface 얻기 
	IX *pIX = NULL;
	HRESULT = hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
	pIUnknown->Release();

	if(SUCCEEDED(hr))
	{
		pIX->Fx();			// 인터페이스 사용
		IX *pIX2 = pIX;

		pIX2->AddRef();		// 복사시 참조 카운트 증가 
		pIX2->Fx();

		pIX2->Release();	// 감소 
		pIX->Release();		
	}
//	pIUnknown->Release();
}
// 위의 예에서 pIX2->AddRef();	pIX2->Release();
// 호출이 필요할까??  
*/