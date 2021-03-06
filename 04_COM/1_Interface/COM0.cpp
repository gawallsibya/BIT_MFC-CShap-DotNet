/*******************************************************************

  COM ( Component Object Model )

*******************************************************************/

/*
//-------------------------------------------------------------------
  용어 정리 
/--------------------------------------------------------------------

	COM
	  - 한 덩어리의 애플리케이션을 컴포넌트로 분리하는데 필요한 도구

      - 컴포넌트를 만들고 이 컴포넌트에서 애플리케이션을 구축하는 방법
	    에 대한 명세(Specification)

        언어가 아니다.
	    DLL이 아니다.
		API와 같은 함수가 아니다.
		클래서 라이브러리도 아니다.

      - COM 라이브러리를 지원한다.
	    모든 클라이언트와 컴포넌트에게 유용한 컴포넌트 관리 서비스 제공 
		

    COMPONENT
	  - 한 덩어리의 소프트웨어를 분리했을 때 개념상의 추상적 단위
	   
		 하나의 COM객체가 component가 될 수도 있고 여러개의 com객체가
		 합쳐져서 하나의 component가 될 수 있다.

	COM객체 
	  - COM 표준 인터페이스를 상속받아 명세에 맞게 구현해 놓은 C++객체



    *) COMPONENT PROGRAMMING : 한 덩어리의 소프트웨어를 여러개의 작은 
	        덩어리로 나누어 programming

       기존 PROGRAMMING기법  : 큰 덩어리를 조금씩 만들어 가는 것 


//-------------------------------------------------------------------
  컴포넌트의 장점 
/--------------------------------------------------------------------

    application 커스터마이즈
	  - 기능을 쉽게 개선 확장 시킬 수 있다.
	  
	컴포넌트 라이브러리 
	  - 레고 블록들 처럼 미리 구현된 라이브러리 컴포넌트를 이용하여 
	    쉽고 빠르게 소프트웨어 부품을 조립하여 완성시켜 갈 수 있다.

    분산 컴포넌트 
	  - 위치 투명성을 가지고 있어서 원격 시스템에 있는 컴포넌트 사용또한
	    가능하다.



//-------------------------------------------------------------------
  컴포넌트 요구사항 
/--------------------------------------------------------------------
   
	 동적 링크 기능
	   - 정적 링크 : 시스템에서 원하는 컴포넌트중 하나를 변경시키기 원한
	     다면, 정적으로 다시 링크하고 컴파일 한 후에 그것을 다시 배포해야 함


     캡슐화 기능 
	    - 컴포넌트 교환시 새로운 컴포넌트는 기존의 컴포넌트와 같은 방법으로
		  연결되어야 함
		  그렇지 않다면, 컴포넌트를 새로이 작성하고 컴파일하고 링크해야 함

        - 컴포넌트의 구현시에 클라이언트를 분리하기 위한 조건
		  1) 컴포넌트는 구현에 사용된 컴퓨터 언어를 숨겨야 함
		     - 언어를 알리게 되면 종속성이 생기게 됨
		  2) 컴포넌트는 2진 파일 형식으로 전달되어야 함
		     - C++ 은 코드 재사용 
          3) 기존의 사용자를 그대로 유지하면서 업그레이드가 되어야 함
		     - 버전 관리 
		  4) 네트웤 상에서 투명하게 재배치 가능해야 함 
 


//-------------------------------------------------------------------
  COM COMPONENT의 특징 (COM 객체)
    - MS의 COM 규칙에 맞게 구현된 컴포넌트 
/--------------------------------------------------------------------

  - 동적으로 링크된다. : DLL을 사용함

  - 완벽한 캡슐화가 지원된다.
    
	언어에 독립적이다.
	이진 파일 형태의 포멧으로 전달된다.
	기존의 클라이언트에 아무런 변화를 가하지 않고 업그레이드 가능
	네트웤 상에서 투명하게 재배치 가능 


*/