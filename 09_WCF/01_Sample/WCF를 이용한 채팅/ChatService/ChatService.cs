// 참고자료: Nikola Paljetak
// 만든이: 박경훈(HOONS)
// 닷넷 커뮤니티 : HOONS닷넷 - http://www.hoonsbara.com

using System;
using System.Collections;
using System.Collections.Generic;
using System.ServiceModel;

namespace NikeSoftChat
{

  #region 1. 메세지 관련 Contract InterFace (클라이언트->서버)

  /// ////////////////////////////////////////////////////////////////////////
  /// InstanceContextMode.PerSession이므로 세션을 사용함
  /// -->그렇기 때문에 신뢰할 수 있는 전송 세션 이용해야함
  /// ////////////////////////////////////////////////////////////////////////
  [ServiceContract(SessionMode = SessionMode.Required, CallbackContract = typeof(IChatCallback))]
  interface IChat
  {
    /// ////////////////////////////////////////////////////////////////////////
    /// IsTerminating : 메서드가 호출되고 반환되는 시점에 세션을 자동 종료될지 여부
    /// IsInitiating :  세션이 최초로 맺어지는 단계에서 호출이 가능여부
    /// ////////////////////////////////////////////////////////////////////////
    [OperationContract(IsOneWay = false, IsInitiating = true, IsTerminating = false)]
    string[] Join(string name);

    [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = false)]
    void Say(string msg);

    [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = false)]
    void Whisper(string to, string msg);

    [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = true)]
    void Leave();
  }
  #endregion

  
  #region 2. 클라이언트에 콜백할 CallBackContract  (서버->클라이언트)

  interface IChatCallback
  {
    [OperationContract(IsOneWay = true)]
    void Receive(string senderName, string message);

    [OperationContract(IsOneWay = true)]
    void ReceiveWhisper(string senderName, string message);

    [OperationContract(IsOneWay = true)]
    void UserEnter(string name);

    [OperationContract(IsOneWay = true)]
    void UserLeave(string name);
  }
  #endregion


  #region 3. 메세지 타입&이벤트Agrs정의

  //메세지 타입
  public enum MessageType { Receive, UserEnter, UserLeave, ReceiveWhisper };

  //ChatEventArgs 이벤트 Arg에 포함될 항목
  public class ChatEventArgs : EventArgs
  {
    public MessageType msgType;
    public string name;
    public string message;
  }

  #endregion


  #region 4. 실제 서비스 구현(클라이언트->서버)
  /// /////////////////////////////////////////////////////////////////////
  /// InstanceContextMode  ->  PerSession:세션과 같은 인스턴스
  /// ConcurrencyMode ->  Multiple: 멀티 스레드 지원
  ////////////////////////////////////////////////////////////////////////
  [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession, ConcurrencyMode = ConcurrencyMode.Multiple)]
  public class ChatService : IChat
  {

    #region 4.1. 전역 변수및 COMMON 메서드
    //동기화 작업을 위해서 가상의 객체 생성
    private static Object syncObj = new Object();

    //콜백 이벤트로 실행
    IChatCallback callback = null;

    //콜백 델리게이트와 이벤트선언
    public delegate void ChatEventHandler(object sender, ChatEventArgs e);
    public static event ChatEventHandler ChatEvent;

    //키와 값을 가지고 있는 컬렉셔, Key=string 타입, 값은 ChatEventHandler를 가지고 있는다.
    static Dictionary<string, ChatEventHandler> chatters = new Dictionary<string, ChatEventHandler>();

    //키가 될 이름
    private string name;
    //채팅 이벤트
    private ChatEventHandler myEventHandler = null;


    /// <summary>
    /// 전체 클라이언트들에게 이벤트를 전달한다.
    /// </summary>
    /// <param name="e"></param>
    private void BroadcastMessage(ChatEventArgs e)
    {
      //이벤트
      ChatEventHandler temp = ChatEvent;

      if (temp != null)
      {
        //현재 이벤트들을 전달한다.
        foreach (ChatEventHandler handler in temp.GetInvocationList())
        {
          handler.BeginInvoke(this, e, new AsyncCallback(EndAsync), null);
        }
      }
    }


    /// <summary>
    /// 클라이언트에게 이벤트를 전달한다.
    /// </summary>
    /// <param name="ar"></param>
    private void EndAsync(IAsyncResult ar)
    {
      ChatEventHandler d = null;

      try
      {
        System.Runtime.Remoting.Messaging.AsyncResult asres = (System.Runtime.Remoting.Messaging.AsyncResult)ar;
        d = ((ChatEventHandler)asres.AsyncDelegate);
        d.EndInvoke(ar);
      }
      catch
      {
        ChatEvent -= d;
      }
    }


    /// <summary>
    /// 이벤트 발생
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void MyEventHandler(object sender, ChatEventArgs e)
    {
      try
      {
        //클라이언트에게 보내기
        switch (e.msgType)
        {
          case MessageType.Receive:
            callback.Receive(e.name, e.message);
            break;
          case MessageType.ReceiveWhisper:
            callback.ReceiveWhisper(e.name, e.message);
            break;
          case MessageType.UserEnter:
            callback.UserEnter(e.name);
            break;
          case MessageType.UserLeave:
            callback.UserLeave(e.name);
            break;
        }
      }
      catch//에러가 발생했을 경우
      {
        Leave();
      }
    }

    #endregion

    #region 4.2. JOIN 메서드

    /// <summary>
    /// * JOIN 메서드 
    /// 특정한 사용자가 방에 처음 들어 왔을때 사용자의 이름을 받아서 
    /// 처리한다.
    /// </summary>
    /// <param name="name">사용자 이름</param>
    /// <returns>같은 이름이 없을 경우에는 사용자 리스트를 반환한다</returns>
    public string[] Join(string name)
    {
      myEventHandler = new ChatEventHandler(MyEventHandler);

      lock (syncObj)
      {
        if (!chatters.ContainsKey(name))//이름이 기존 채터에 있는지 검색한다.
        {
          //이름과 이벤트를 추가한다.
          this.name = name;
          chatters.Add(name, MyEventHandler);
          
          //사용자에게 보내 줄 채널을 설정한다.
          callback = OperationContext.Current.GetCallbackChannel<IChatCallback>();

          //UserEnter 라는 이벤트를 전달한다
          ChatEventArgs e = new ChatEventArgs();
          e.msgType = MessageType.UserEnter;
          e.name = name;
          BroadcastMessage(e);

          //델리게이터 추가
          ChatEvent += myEventHandler;

          //사용자리스트를 보내준다.
          string[] list = new string[chatters.Count];
          lock (syncObj)
          {
            chatters.Keys.CopyTo(list, 0);
          }
          return list;
        }
        else //이미 사용자가 사용하고 있는 이름일 경우
        {
          return null;
        }
      }
    }
    #endregion

    #region 4.3. Say메서드
    public void Say(string msg)
    {
      ChatEventArgs e = new ChatEventArgs();
      e.msgType = MessageType.Receive;
      e.name = this.name;
      e.message = msg;
      BroadcastMessage(e);
    }
    #endregion

    #region 4.4. 귓속말
    public void Whisper(string to, string msg)
    {
      ChatEventArgs e = new ChatEventArgs();
      e.msgType = MessageType.ReceiveWhisper;
      e.name = this.name;
      e.message = msg;
      try
      {
        ChatEventHandler chatterTo;
        lock (syncObj)
        {
          chatterTo = chatters[to];
        }
        chatterTo.BeginInvoke(this, e, new AsyncCallback(EndAsync), null);
      }
      catch (KeyNotFoundException)
      {
      }
    }
    #endregion

    #region 4.5. 방나가기
    public void Leave()
    {
      if (this.name == null) return;

      lock (syncObj)
      {
        chatters.Remove(this.name);
      }
      ChatEvent -= myEventHandler;

      //새로운 이벤트 발생
      ChatEventArgs e = new ChatEventArgs();
      e.msgType = MessageType.UserLeave;
      e.name = this.name;
      BroadcastMessage(e);
    }
    #endregion 

  }
  #endregion

}