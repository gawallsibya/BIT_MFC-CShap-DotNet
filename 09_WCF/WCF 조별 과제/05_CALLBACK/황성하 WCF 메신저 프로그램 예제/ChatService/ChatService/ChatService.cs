using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.ServiceModel;
using System.Threading.Tasks;

namespace Chating
{
    #region 1. 메세지 관련 Contract InterFace (클라이언트->서버)
    [ServiceContract(SessionMode = SessionMode.Required, CallbackContract = typeof(IChatCallback))]
    public interface IChat
    {
        [OperationContract(IsOneWay = false, IsInitiating = true, IsTerminating = false)]
        string[] Join(string name);

        [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = false)]
        void Say(string msg);

        [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = true)]
        void Leave();
    }
    #endregion

    #region 2. 클라이언트에 콜백할 CallBackContract  (서버->클라이언트)
    public interface IChatCallback
    {
        [OperationContract(IsOneWay = true)]
        void Receive(string senderName, string message);

        [OperationContract(IsOneWay = true)]
        void UserEnter(string name);

        [OperationContract(IsOneWay = true)]
        void UserLeave(string name);
    }
    #endregion

    class ChatService : IChat
    {
        public delegate void Chat(string name, string msg, string type);

        //동기화 작업을 위해서 가상의 객체 생성
        private static Object syncObj = new Object();
        //델리게이트 리스트 생성
        private static Chat List;
        //채팅방에 있는 유저 이름 목록
        private static ArrayList Chatter = new ArrayList();
        //키가됄 이름
        private string name;
        //개인 델리게이트
        private Chat MyChat;

        IChatCallback callback = null;

        private void UserHandler(string name, string msg, string msgType)
        {
            try
            {
                //클라이언트에게 보내기
                switch (msgType)
                {
                    case "Receive":
                        callback.Receive(name, msg);
                        break;
                    case "UserEnter":
                        callback.UserEnter(name);
                        break;
                    case "UserLeave":
                        callback.UserLeave(name);
                        break;
                }
            }
            catch//에러가 발생했을 경우
            {
                Leave();
            }
        }

        private void BroadcastMessage(string name, string msg, string msgType)
        {
            if (List != null)
            {
                //현재 이벤트들을 전달한다.
                foreach (Chat handler in List.GetInvocationList())
                {
                    handler.BeginInvoke(name, msg, msgType, new AsyncCallback(EndAsync), null);
                }
            }
        }

        private void EndAsync(IAsyncResult ar)
        {
            Chat d = null;
            try
            {
                System.Runtime.Remoting.Messaging.AsyncResult asres = (System.Runtime.Remoting.Messaging.AsyncResult)ar;
                d = ((Chat)asres.AsyncDelegate);
                d.EndInvoke(ar);
            }
            catch
            {
                List -= d;
            }
        }

        public string[] Join(string name)
        {
            MyChat = new Chat(UserHandler);
            lock (syncObj)
            {
                if (!Chatter.Contains(name)) //이름이 기존 채터에 있는지 검색한다.
                {
                    //이름과 이벤트를 추가한다.
                    this.name = name;
                    Chatter.Add(name);

                    //사용자에게 보내 줄 채널을 설정한다.
                    callback = OperationContext.Current.GetCallbackChannel<IChatCallback>();

                    //현재 접속자 정보를 모두에게 전달
                    BroadcastMessage(name, "", "UserEnter");

                    //델리게이터 추가
                    List += MyChat;

                    //사용자리스트를 보내준다.
                    string[] list = new string[Chatter.Count];
                    lock (syncObj)
                    {
                        Chatter.CopyTo(list);
                    }
                    return list;
                }
                else //이미 사용자가 사용하고 있는 이름일 경우
                {
                    return null;
                }
            }
        }

        public void Say(string msg)
        {
            BroadcastMessage(this.name, msg, "Receive");
        }

        public void Leave()
        {
            if (this.name == null) return;

            lock (syncObj)
            {
                Chatter.Remove(this.name);
            }
            List -= MyChat;

            string msg = string.Format(this.name + "이가 나갔습니다");
            BroadcastMessage(this.name, msg, "UserLeave");
        }
    }
}
