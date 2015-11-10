//--------------------------------------------------------------
// #define WIN32_LEAN_AND_MEAN
// h파일 충돌 처리 
//----------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN // windows.h 에서 자주 사용하지 않은 것은 컴파일에서
							// 제외 한다. winsock2.h 와의 충돌을 막아 준다.
// Server
// 1. socket 생성 
// 2. IP, PORT를 bind 해줌
// 3. Listen()
// 4. accept()
// receive
// Client가 접속할때까지...

// Client
// 1. socket 생성
// 2. connect()
// 3. server의 accept로부터 socket()
// send

// project setting에서 바꿔준다.
// object/library modules에 ws2_32.lib 써준다.

// 서버 함수
#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <process.h> // 스레드를 사용하기 위함
#include <list>
using namespace std;
// 서버에 data를 전송하는 thread

list<SOCKET> sockList;

void foo(void* p){
	SOCKET s = (SOCKET)p;

	char buf[256];
	while(1){
		int n = recv(s, buf, 256, 0);
		if (n >0){
			list<SOCKET>::iterator p = sockList.begin();
			while ( p != sockList.end() ){
				send(*p, buf, n, 0);
				p++;
			}
		}		
	}
}


/*
void foo(void* p){
	SOCKET s = (SOCKET)p;

	char buf[256];
	while(1){
		cin >> buf;
		send(s, buf, strlen(buf), 0);
	}	
}
*/
void main()
{
	// 소켓 초기화
	// 초기화 함수 WSAStartup() 이용 버전 2.0을 사용하라는 뜻
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// 서버 소켓 생성
	// AF_INET => 인터넷이라는 뜻
	// SOCK_STREAM => tcp로 하겠다는 뜻 
	// SOCKET 은 int형 번호임.
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); // TCP / IP

	// bind
	// SOCKADDR_IN 이라는 구조체 사용
	SOCKADDR_IN addr; 
	addr.sin_family = AF_INET; // 인터넷 주소
	addr.sin_port = 5252;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int namelen = sizeof(addr);	

	// (SOCKADDR*)으로 casting 하는 이유?
	// 인터넷 주소와 이더넷 등 주소크기가 전부 다르므로.
	if ( bind(s, (SOCKADDR*)&addr, namelen) == -1)
	{
		cout << "error in bind" << endl;
		return;
	}
////////////////////////////////////////////////////
	// listen
	// listen 함수를 부른다. 동시 접속시 대기자는 
	// 5명으로 제한.
	while(1)
	{
		if (listen(s, 5) == -1)
		{
			cout << "error in listen" << endl;
			return;
		}

		cout << "Wating Client....." << endl;

		SOCKADDR_IN addr_client;
		int len = sizeof(addr_client);

	// accept 부르는 순간 멈춘다. 누군가 접속할때까지 
	
		SOCKET client = accept( s, (SOCKADDR*)&addr_client, &len);

		sockList.push_back(client);
	
///////////////////////////////////////////////////////
	cout << "connected clented...." << endl;

	// 새로운 스레드를 생성해서 서버에서 오는 를 받는다.
	// foo라는 함수를 새로운 thread로 돌리면서 foo에 파라미터로
	// data를 넘겨준다.
// printf와 scanf는 멀티  thread를 같이 못쓴다.
	// project setting 에서 c/c++ 에서 general 
	// 수신 후에 list에 있는 모든 client에 되돌린다.
	_beginthread(foo, 0, (void*)client);
	// 소켓 cleanup
	}
	WSACleanup();
}