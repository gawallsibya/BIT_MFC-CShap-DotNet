using System;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Text;

namespace Server
{
    /******************************************************************************
     * 기능 = 데이터를 받은뒤 처리를 Handler에서 처리하도록 하는 함수
     * 인자 = 1. 소켓 객체 (보통 this를 넘김)
     *        2. 받은 데이터 
     *        3. Size값
     *        4. 해당 스레드에 배정돼있는 client socket 값
    *******************************************************************************/
    delegate void Recvfun(byte[] data, int size, Socket sock);
    delegate void RecvLog(string str, Socket sock);

    class ServerSock
    {
        private ArrayList ar = new ArrayList();
        private Socket server;
        private Thread Acc;
        private Thread Recv;
        private Recvfun recvfun;
        private RecvLog recvlog;

        #region 소켓 라이브러리 및 초기화
        public void initSock(int Port)
        {
            IPEndPoint ipep = new IPEndPoint(IPAddress.Any, Port);
            server = new Socket(AddressFamily.InterNetwork,
                                                  SocketType.Stream, ProtocolType.Tcp);
            server.Bind(ipep);
            server.Listen(20);

            //접속 쓰레드
            Acc = new Thread(new ThreadStart(this.Accept));
            Acc.Start();
        }
        #endregion


        #region 소켓 종료
        public void Dispose()
        {
            server.Close();
        }
        #endregion

        #region Delegate 초기화
        public void initDele(Recvfun recv, RecvLog log)
        {
            recvfun = new Recvfun(recv);
            recvlog = new RecvLog(log);
        }
        #endregion

        #region Accept 쓰레드
        public void Accept()
        {
            while (true)
            {
                Socket client = server.Accept();  // 클라이언트 접속 대기

                // 접속한 클라이언트 아이피 주소와 접속 포트번호 출력
                IPEndPoint ip = (IPEndPoint)client.RemoteEndPoint;
                Console.WriteLine("{0}주소, {1}포트 접속", ip.Address, ip.Port);

                //쓰레드 생성
                Recv = new Thread(new ParameterizedThreadStart(this.ThreadProc));
                Recv.Start(client);

                //클라이언트 소켓 저장
                ar.Add(client);

                //Log 
                recvlog("connect", client);

                //foreach (string temp in data)
                //{
                //    System.Threading.Thread.Sleep(10);
                //    SendData(client, Encoding.Default.GetBytes(temp));
                //}        
            }
        }
        #endregion

        #region Recv 쓰레드
        public void ThreadProc(Object sock)
        {
            while (true)
            {
                bool ret = ReceiveData((Socket)sock);
                if (ret == false)   
                {
                    ar.Remove(sock);
                    return;
                }
            }
        }
        #endregion


        #region SendAll
        public void SendAlldata(Socket sock, string str)
        {
            byte[] data = new byte[str.Length];
            data = Encoding.Default.GetBytes(str);
            foreach (Socket temp in ar)
            {
                SendData(temp, data);
            }
        }
        #endregion

        #region Send
        public void SendData(Socket sock, byte[] data)
        {
            try
            {
                int total = 0;
                int size  = data.Length;
                int left_data = size;
                int send_data = 0;

                // 전송할 데이터의 크기 전달
                byte[] data_size = new byte[4];
                data_size = BitConverter.GetBytes(size);
                send_data = sock.Send(data_size);


                // 실제 데이터 전송
                while (total < size)
                {
                    send_data = sock.Send(data, total, left_data, SocketFlags.None);
                    total += send_data;
                    left_data -= send_data;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        #endregion

        #region Recv
        public bool ReceiveData(Socket sock)
        {
            try
            {
                int total = 0;
                int size = 0;
                int left_data = 0;
                int recv_data = 0;

                // 수신할 데이터 크기 알아내기 
                byte[] data_size = new byte[4];
                recv_data = sock.Receive(data_size, 0, 4, SocketFlags.None);
                size = BitConverter.ToInt32(data_size, 0);
                left_data = size;

                byte[] Data = new byte[size];

                // 실제 데이터 수신
                while (total < size)
                {
                    recv_data = sock.Receive(Data, total, left_data, 0);
                    if (recv_data == 0) break;
                    total += recv_data;
                    left_data -= recv_data;
                }

                //수신됀 데이타를 처리
                recvfun( Data, size, sock);

                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }
        }
        #endregion

    }
}
