// chat Client
#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <process.h>
using namespace std;

// �������Լ� �������� ���� data�� �޴´�.
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
	// ���� �ʱ�ȭ
	// �ʱ�ȭ �Լ� WSAStartup() �̿� ���� 2.0�� ����϶�� ��
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	// Ŭ���Ʈ ���� ����
	// AF_INET => ���ͳ��̶�� ��
	// SOCK_STREAM => tcp�� �ϰڴٴ� �� 
	// SOCKET �� int�� ��ȣ��.
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0); // TCP / IP

	// bind
	// SOCKADDR_IN �̶�� ����ü ���
	SOCKADDR_IN addr; 
	addr.sin_family = AF_INET; // ���ͳ� �ּ�
	addr.sin_port = 4000;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ���� ip

	// inet_addr()�� char�� 4���� �������.
	int namelen = sizeof(addr);

	// ������ ������ �õ��Ѵ�.

	cout << "conneting Server...." << endl;

	if(connect(s, (SOCKADDR*)&addr, namelen) == -1){
		cout << "can't connect server" << endl;
		return;
	}


	cout << "connected server" << endl;
////////////////////////////////////////////////////

	// ���ο� �����带 �����ؼ� �������� ���� data�� �޴´�.
	// foo��� �Լ��� ���ο� thread�� �����鼭 foo�� �Ķ���ͷ�
	// data�� �Ѱ��ش�.
	// printf�� scanf�� ��Ƽ  thread�� ���� ������.
	// ���� �ɼǿ��� multithread�� �����������.
	// project setting ���� c/c++ ���� general 
	// code generation =>user run_time library����
	// debug Multithread ����
	_beginthread(foo, 0, (void*)s);
	
	// ������ data ����...	

	char buf[256];
	while(1){
		cin >> buf;
		send(s, buf, strlen(buf), 0);
	}
	WSACleanup();
}