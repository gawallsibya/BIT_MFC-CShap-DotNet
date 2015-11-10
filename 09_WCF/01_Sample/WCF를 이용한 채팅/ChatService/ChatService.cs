// �����ڷ�: Nikola Paljetak
// ������: �ڰ���(HOONS)
// ��� Ŀ�´�Ƽ : HOONS��� - http://www.hoonsbara.com

using System;
using System.Collections;
using System.Collections.Generic;
using System.ServiceModel;

namespace NikeSoftChat
{

  #region 1. �޼��� ���� Contract InterFace (Ŭ���̾�Ʈ->����)

  /// ////////////////////////////////////////////////////////////////////////
  /// InstanceContextMode.PerSession�̹Ƿ� ������ �����
  /// -->�׷��� ������ �ŷ��� �� �ִ� ���� ���� �̿��ؾ���
  /// ////////////////////////////////////////////////////////////////////////
  [ServiceContract(SessionMode = SessionMode.Required, CallbackContract = typeof(IChatCallback))]
  interface IChat
  {
    /// ////////////////////////////////////////////////////////////////////////
    /// IsTerminating : �޼��尡 ȣ��ǰ� ��ȯ�Ǵ� ������ ������ �ڵ� ������� ����
    /// IsInitiating :  ������ ���ʷ� �ξ����� �ܰ迡�� ȣ���� ���ɿ���
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

  
  #region 2. Ŭ���̾�Ʈ�� �ݹ��� CallBackContract  (����->Ŭ���̾�Ʈ)

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


  #region 3. �޼��� Ÿ��&�̺�ƮAgrs����

  //�޼��� Ÿ��
  public enum MessageType { Receive, UserEnter, UserLeave, ReceiveWhisper };

  //ChatEventArgs �̺�Ʈ Arg�� ���Ե� �׸�
  public class ChatEventArgs : EventArgs
  {
    public MessageType msgType;
    public string name;
    public string message;
  }

  #endregion


  #region 4. ���� ���� ����(Ŭ���̾�Ʈ->����)
  /// /////////////////////////////////////////////////////////////////////
  /// InstanceContextMode  ->  PerSession:���ǰ� ���� �ν��Ͻ�
  /// ConcurrencyMode ->  Multiple: ��Ƽ ������ ����
  ////////////////////////////////////////////////////////////////////////
  [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession, ConcurrencyMode = ConcurrencyMode.Multiple)]
  public class ChatService : IChat
  {

    #region 4.1. ���� ������ COMMON �޼���
    //����ȭ �۾��� ���ؼ� ������ ��ü ����
    private static Object syncObj = new Object();

    //�ݹ� �̺�Ʈ�� ����
    IChatCallback callback = null;

    //�ݹ� ��������Ʈ�� �̺�Ʈ����
    public delegate void ChatEventHandler(object sender, ChatEventArgs e);
    public static event ChatEventHandler ChatEvent;

    //Ű�� ���� ������ �ִ� �÷���, Key=string Ÿ��, ���� ChatEventHandler�� ������ �ִ´�.
    static Dictionary<string, ChatEventHandler> chatters = new Dictionary<string, ChatEventHandler>();

    //Ű�� �� �̸�
    private string name;
    //ä�� �̺�Ʈ
    private ChatEventHandler myEventHandler = null;


    /// <summary>
    /// ��ü Ŭ���̾�Ʈ�鿡�� �̺�Ʈ�� �����Ѵ�.
    /// </summary>
    /// <param name="e"></param>
    private void BroadcastMessage(ChatEventArgs e)
    {
      //�̺�Ʈ
      ChatEventHandler temp = ChatEvent;

      if (temp != null)
      {
        //���� �̺�Ʈ���� �����Ѵ�.
        foreach (ChatEventHandler handler in temp.GetInvocationList())
        {
          handler.BeginInvoke(this, e, new AsyncCallback(EndAsync), null);
        }
      }
    }


    /// <summary>
    /// Ŭ���̾�Ʈ���� �̺�Ʈ�� �����Ѵ�.
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
    /// �̺�Ʈ �߻�
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void MyEventHandler(object sender, ChatEventArgs e)
    {
      try
      {
        //Ŭ���̾�Ʈ���� ������
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
      catch//������ �߻����� ���
      {
        Leave();
      }
    }

    #endregion

    #region 4.2. JOIN �޼���

    /// <summary>
    /// * JOIN �޼��� 
    /// Ư���� ����ڰ� �濡 ó�� ��� ������ ������� �̸��� �޾Ƽ� 
    /// ó���Ѵ�.
    /// </summary>
    /// <param name="name">����� �̸�</param>
    /// <returns>���� �̸��� ���� ��쿡�� ����� ����Ʈ�� ��ȯ�Ѵ�</returns>
    public string[] Join(string name)
    {
      myEventHandler = new ChatEventHandler(MyEventHandler);

      lock (syncObj)
      {
        if (!chatters.ContainsKey(name))//�̸��� ���� ä�Ϳ� �ִ��� �˻��Ѵ�.
        {
          //�̸��� �̺�Ʈ�� �߰��Ѵ�.
          this.name = name;
          chatters.Add(name, MyEventHandler);
          
          //����ڿ��� ���� �� ä���� �����Ѵ�.
          callback = OperationContext.Current.GetCallbackChannel<IChatCallback>();

          //UserEnter ��� �̺�Ʈ�� �����Ѵ�
          ChatEventArgs e = new ChatEventArgs();
          e.msgType = MessageType.UserEnter;
          e.name = name;
          BroadcastMessage(e);

          //���������� �߰�
          ChatEvent += myEventHandler;

          //����ڸ���Ʈ�� �����ش�.
          string[] list = new string[chatters.Count];
          lock (syncObj)
          {
            chatters.Keys.CopyTo(list, 0);
          }
          return list;
        }
        else //�̹� ����ڰ� ����ϰ� �ִ� �̸��� ���
        {
          return null;
        }
      }
    }
    #endregion

    #region 4.3. Say�޼���
    public void Say(string msg)
    {
      ChatEventArgs e = new ChatEventArgs();
      e.msgType = MessageType.Receive;
      e.name = this.name;
      e.message = msg;
      BroadcastMessage(e);
    }
    #endregion

    #region 4.4. �ӼӸ�
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

    #region 4.5. �泪����
    public void Leave()
    {
      if (this.name == null) return;

      lock (syncObj)
      {
        chatters.Remove(this.name);
      }
      ChatEvent -= myEventHandler;

      //���ο� �̺�Ʈ �߻�
      ChatEventArgs e = new ChatEventArgs();
      e.msgType = MessageType.UserLeave;
      e.name = this.name;
      BroadcastMessage(e);
    }
    #endregion 

  }
  #endregion

}