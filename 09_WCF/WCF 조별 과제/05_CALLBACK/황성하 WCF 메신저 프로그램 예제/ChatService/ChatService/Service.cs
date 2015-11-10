using System;
using System.Collections;
using System.Collections.Generic;
using System.ServiceModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChatService
{
    [ServiceContract]
    interface IChat
    {
        [OperationContract]
        string[] Join(string name);

        [OperationContract]
        void Send(string msg);

        [OperationContract]
        void Leave(string msg);
    }

    [ServiceContract]
    interface ICallback
    {
        [OperationContract]
        void Receive(string msg);
    }


    class Service : IChat
    {
        public delegate void ChatList(string msg);
        public static ChatList List;
        private ICallback callback;
        private ChatList User;

        public string[] Join(string name)
        {
            User = new ChatList(User);

        }
        public void Send(string msg)
        {
            BroadcastMessage(msg);
        }


        private void BroadcastMessage(string msg)
        {
            //이벤트
            ChatList temp = List;

            if (temp != null)
            {
                //현재 이벤트들을 전달한다.
                foreach (ChatList handler in temp.GetInvocationList())
                {
                    handler.BeginInvoke(msg, new AsyncCallback(EndAsync), null);
                }
            }
        }

        private void EndAsync(IAsyncResult ar)
        {
            ChatList d = null;

            try
            {
                System.Runtime.Remoting.Messaging.AsyncResult asres = (System.Runtime.Remoting.Messaging.AsyncResult)ar;
                d = ((ChatList)asres.AsyncDelegate);
                d.EndInvoke(ar);
            }
            catch
            {
                List -= d;
            }
        }
    }
}
