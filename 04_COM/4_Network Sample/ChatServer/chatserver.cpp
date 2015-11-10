//--------------------------------------------------------------
// #define WIN32_LEAN_AND_MEAN
// h���� �浹 ó�� 
//----------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN // windows.h ���� ���� ������� ���� ���� �����Ͽ���
							// ���� �Ѵ�. winsock2.h ���� �浹�� ���� �ش�.
// Server
// 1. socket ���� 
// 2. IP, PORT�� bind ����
// 3. Listen()
// 4. accept()
// receive
// Client�� �����Ҷ�����...

// Client
// 1. socket ����
// 2. connect()
// 3. server�� accept�κ��� socket()
// send

// project setting���� �ٲ��ش�.
// object/library modules�� ws2_32.lib ���ش�.

// ���� �Լ�
#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <process.h> // �����带 ����ϱ� ����
#include <list>
using namespace std;
// ������ data�� �����ϴ� thread

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
	// ���� �ʱ�ȭ
	// �ʱ�ȭ �Լ� WSAStartup() �̿� ���� 2.0�� ����϶�� ��
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// ���� ���� ����
	// AF_INET => ���ͳ��̶�� ��
	// SOCK_STREAM => tcp�� �ϰڴٴ� �� 
	// SOCKET �� int�� ��ȣ��.
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); // TCP / IP

	// bind
	// SOCKADDR_IN �̶�� ����ü ���
	SOCKADDR_IN addr; 
	addr.sin_family = AF_INET; // ���ͳ� �ּ�
	addr.sin_port = 5252;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int namelen = sizeof(addr);	

	// (SOCKADDR*)���� casting �ϴ� ����?
	// ���ͳ� �ּҿ� �̴��� �� �ּ�ũ�Ⱑ ���� �ٸ��Ƿ�.
	if ( bind(s, (SOCKADDR*)&addr, namelen) == -1)
	{
		cout << "error in bind" << endl;
		return;
	}
////////////////////////////////////////////////////
	// listen
	// listen �Լ��� �θ���. ���� ���ӽ� ����ڴ� 
	// 5������ ����.
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

	// accept �θ��� ���� �����. ������ �����Ҷ����� 
	
		SOCKET client = accept( s, (SOCKADDR*)&addr_client, &len);

		sockList.push_back(client);
	
///////////////////////////////////////////////////////
	cout << "connected clented...." << endl;

	// ���ο� �����带 �����ؼ� �������� ���� �� �޴´�.
	// foo��� �Լ��� ���ο� thread�� �����鼭 foo�� �Ķ���ͷ�
	// data�� �Ѱ��ش�.
// printf�� scanf�� ��Ƽ  thread�� ���� ������.
	// project setting ���� c/c++ ���� general 
	// ���� �Ŀ� list�� �ִ� ��� client�� �ǵ�����.
	_beginthread(foo, 0, (void*)client);
	// ���� cleanup
	}
	WSACleanup();
}