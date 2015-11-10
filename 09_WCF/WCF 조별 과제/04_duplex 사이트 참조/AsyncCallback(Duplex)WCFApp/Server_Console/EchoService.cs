using System;
using System.ServiceModel;
using System.ServiceModel.Channels;
using System.Runtime.Serialization;

[ServiceContract(Namespace="http://xdn-dcpark/WCF/echo/", CallbackContract=typeof(IEchoServiceCallback))]
public interface IEchoService
{
    /// <summary>
    /// Action ������ ������ SOAP �޽����� ���� �޼��� ���� ���� 
    /// �� �޼��带 � SOAP �޽����� ���� ������ ���̴�.
    /// �⺻�� : ������ ���ӽ����̽��� �޼������ �⺻���� �Ͽ� �ڵ� ������.
    /// �Ʒ� Echo�� �⺻ Action = http://xdn-dcpark/WCF/echo/Echo
    /// Action = * : ��ġ�ϴ� �޼��尡 ���� SOAP �޽����� ó���ض�.
    /// </summary>
    /// <param name="msg"></param>
    /// <returns></returns>
    [OperationContract(Action = "urn:echo:string")]
    string Echo(string msg);

    /// <summary>
    /// Message Ÿ���� WCF�� Ư�� ������ Ÿ�����μ� WCF�� ���ϴ� �޽����� ǥ���ϴµ� ����. ������ Ÿ�� ��� Serialization�� �Ͼ�� ����
    /// </summary>
    /// <param name="msg"></param>
    /// <returns></returns>
    [OperationContract(Action = "*")]
    Message EchoMessage(Message msg);

    /// <summary>
    /// Message Ÿ���� �ƴ� Ÿ���� ���� ���, �޼��带 ȣ���ϱ� ���� SOAP �޽��� ���� �����͸� �ش� .NET ��ü���� serialization�� �ʿ���.
    /// </summary>
    /// <param name="p"></param>
    /// <returns></returns>
    [OperationContract]
    Person EchoPerson(Person p);

    [OperationContract(IsOneWay = true)]
    void EchoJobStart(string jobName);
}

public interface IEchoServiceCallback
{
    [OperationContract(IsOneWay = true)]
    void EchoJobEnd(string result);    
}

/// <summary>
/// ���� Ÿ�� ��ü ������ singleton �ν��Ͻ��� ����
/// ���񽺿� ���� ��Ƽ������ ����
/// </summary>
[ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession,ConcurrencyMode = ConcurrencyMode.Multiple)]
public class EchoService : IEchoService
{
    IEchoServiceCallback callback = null;
    string result = string.Empty;

    private int callCount;

    public EchoService()
    {
        result = string.Empty;
        callback = OperationContext.Current.GetCallbackChannel<IEchoServiceCallback>();

    }

    public void EchoJobStart(string jobName)
    {
        ++callCount;

        result = jobName + " is completed!!!�� CALLCOUNT:" + callCount.ToString(); //OperationContext.Current.SessionId;
        System.Threading.Thread.Sleep(5000);
        
        callback.EchoJobEnd(result);
    }

    public string Echo(string msg)
    {
        ++callCount;
        return "Hello: " + msg + "�� CALLCOUNT:" + callCount.ToString();//OperationContext.Current.SessionId;
    }
    public Message EchoMessage(Message msg)
    {
        System.Text.StringBuilder data = new System.Text.StringBuilder(string.Empty);
        System.Xml.XmlWriter writer = System.Xml.XmlTextWriter.Create(data);
        writer.WriteStartElement("return");
        writer.WriteValue(msg.Headers.Action + "_result");
        writer.WriteEndElement();
        writer.Flush();
        msg.WriteBody(writer);
        return msg;
    }
    public Person EchoPerson(Person p)
    {
        ++callCount;
        Person newP = new Person();
        newP.First = "Hello:" + p.First;
        newP.Last = "Hello:" + p.Last + "�� CALLCOUNT:" + callCount.ToString();
        return newP;
    }
    

}


[DataContract(Namespace = "http://xdn-dcpark/WCF/person")]
public class Person
{
    /// <summary>
    /// ���� DataMember �Ӽ��� ���� �ʵ常�� serialize �Ǿ� ����.
    /// </summary>
    [DataMember(Name="first", Order=0)]
    public string First;
    [DataMember(Name="last", Order=1)]
    public string Last;
    /// <summary>
    /// private �ʵ嵵 serialize �� �� �ִ�.
    /// </summary>
    [DataMember(IsRequired=false, Order=2)]
    private string id;    
}

/// <summary>
/// �Ķ���� ��ϰ� ���� Ÿ���� �׻� SOAP ��û/������ BODY�� ���εȴ�. 
/// HEADER�� ����ؾ� �� �ʿ䰡 �ִ� ���, MessageContract�� �̿��� � �ʵ尡 HEADER/BODY�� ���ε����� ������ �� �ִ�.
/// </summary>
//[MessageContract]
//public class EchoPersonMessage
//{
//    [MessageBody]
//    public Person Person;
//    [MessageHeader]
//    public Authorization Authorization;
//}



