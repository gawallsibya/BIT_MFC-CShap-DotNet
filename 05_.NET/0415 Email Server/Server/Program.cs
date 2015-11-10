using System;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Text;

namespace Server
{
    class Program
    {
        private ServerSock sock;
        private ArrayList data;

        #region RecvFun
        public void recvLog(string str, Socket s)
        {
            //최초 접속시 리스트 정보 전달
            if (str == "connect")
            {
                foreach(string s_data in data)
                {
                     byte[] d = new byte[s_data.Length];                    
                    {
                        d = Encoding.Default.GetBytes(s_data);
                        sock.SendData(s, d);
                    }
                }
            }
        }

        public void recvfun(byte[] d, int size, Socket s)
        {
            Console.WriteLine("Recv  : " + Encoding.Default.GetString(d));             
            sock.SendAlldata(s, Encoding.Default.GetString(d));
            data.Add(Encoding.Default.GetString(d));
            
        }
        #endregion

        public Program()
        {
            sock = new ServerSock();
            sock.initSock(7000);
            Console.WriteLine("서버 시작... 클라이언트 접속 대기중...");
            sock.initDele(recvfun, recvLog);
            data = new ArrayList();
            string temp;
            temp = string.Format("1\f0\a3\a2014-3-4\a민기\a조장\a똑바로햇");
            data.Add(temp);
            temp = string.Format("1\f0\a2\a2014-3-5\a성하\a조원1\a너나잘햇");
            data.Add(temp);
            temp = string.Format("1\f0\a1\a2014-3-6\a우창\a조원2\a감히?");
            data.Add(temp);
            temp = string.Format("1\f0\a0\a2014-3-7\a연상\a조원3\a아아 시끄러어~");
            data.Add(temp);
            temp = string.Format("1\f0\a0\a2014-3-8\a진첩\a조원4\a네..네");
            data.Add(temp);
        }
        static void Main(string[] args)
        {
            Program programe = new Program();
     

            Console.ReadKey();
            //sock.Dispose();
        }
    }
}
