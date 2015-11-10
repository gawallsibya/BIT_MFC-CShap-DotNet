// chat Client
#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <process.h>
using namespace std;

// 스레드함수 서버에서 오는 data를 받는다.
void foo(void* p){
	SOCKET s = (SOCKET)p;

	char buf[256];
	while(1){
		int n = recv(s, buf, 256, 0);
		if (n >0){
			buf[n] = '\0';
			cout << buf << endl;
		}		
	}
}

void main(){
	// 소켓 초기화
	// 초기화 함수 WSAStartup() 이용 버전 2.0을 사용하라는 뜻
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// 클라언트 소켓 생성
	// AF_INET => 인터넷이라는 뜻
	// SOCK_STREAM => tcp로 하겠다는 뜻 
	// SOCKET 은 int형 번호임.
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); // TCP / IP

	// bind
	// SOCKADDR_IN 이라는 구조체 사용
	SOCKADDR_IN addr; 
	addr.sin_family = AF_INET; // 인터넷 주소
	addr.sin_port = 4000;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 서버 ip

	// inet_addr()을 char값 4개로 만들어줌.
	int namelen = sizeof(addr);

	// 서버에 접속을 시도한다.

	cout << "conneting Server...." << endl;

	if(connect(s, (SOCKADDR*)&addr, namelen) == -1){
		cout << "can't connect server" << endl;
		return;
	}


	cout << "connected server" << endl;
////////////////////////////////////////////////////

	// 새로운 스레드를 생성해서 서버에서 오는 data를 받는다.
	// foo라는 함수를 새로운 thread로 돌리면서 foo에 파라미터로
	// data를 넘겨준다.
	// printf와 scanf는 멀티  thread를 같이 못쓴다.
	// 따라서 옵션에서 multithread를 선택해줘야함.
	// project setting 에서 c/c++ 에서 general 
	// code generation =>user run_time library에서
	// debug Multithread 선택
	_beginthread(foo, 0, (void*)s);
	
	// 서버에 data 전송...	

	char buf[256];
	while(1){
		cin >> buf;
		send(s, buf, strlen(buf), 0);
	}
	WSACleanup();
}