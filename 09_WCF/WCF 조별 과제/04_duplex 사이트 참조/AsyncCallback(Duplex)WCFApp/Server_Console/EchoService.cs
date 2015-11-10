using System;
using System.ServiceModel;
using System.ServiceModel.Channels;
using System.Runtime.Serialization;

[ServiceContract(Namespace="http://xdn-dcpark/WCF/echo/", CallbackContract=typeof(IEchoServiceCallback))]
public interface IEchoService
{
    /// <summary>
    /// Action 설정은 들어오는 SOAP 메시지에 대한 메서드 맵핑 정보 
    /// 이 메서드를 어떤 SOAP 메시지가 오면 실행할 것이다.
    /// 기본값 : 서비스의 네임스페이스와 메서드명을 기본으로 하여 자동 생성됨.
    /// 아래 Echo의 기본 Action = http://xdn-dcpark/WCF/echo/Echo
    /// Action = * : 일치하는 메서드가 없는 SOAP 메시지를 처리해라.
    /// </summary>
    /// <param name="msg"></param>
    /// <returns></returns>
    [OperationContract(Action = "urn:echo:string")]
    string Echo(string msg);

    /// <summary>
    /// Message 타입은 WCF의 특수 데이터 타입으로서 WCF를 통하는 메시지를 표현하는데 사용됨. 별도의 타입 기반 Serialization이 일어나지 않음
    /// </summary>
    /// <param name="msg"></param>
    /// <returns></returns>
    [OperationContract(Action = "*")]
    Message EchoMessage(Message msg);

    /// <summary>
    /// Message 타입이 아닌 타입이 사용된 경우, 메서드를 호출하기 위해 SOAP 메시지 상의 데이터를 해당 .NET 객체로의 serialization이 필요함.
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
/// 서비스 타입 객체 생성은 singleton 인스턴스로 관리
/// 서비스에 대한 멀티스레드 지원
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

        result = jobName + " is completed!!!■ CALLCOUNT:" + callCount.ToString(); //OperationContext.Current.SessionId;
        System.Threading.Thread.Sleep(5000);
        
        callback.EchoJobEnd(result);
    }

    public string Echo(string msg)
    {
        ++callCount;
        return "Hello: " + msg + "■ CALLCOUNT:" + callCount.ToString();//OperationContext.Current.SessionId;
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
        newP.Last = "Hello:" + p.Last + "■ CALLCOUNT:" + callCount.ToString();
        return newP;
    }
    

}


[DataContract(Namespace = "http://xdn-dcpark/WCF/person")]
public class Person
{
    /// <summary>
    /// 오직 DataMember 속성을 가진 필드만이 serialize 되어 진다.
    /// </summary>
    [DataMember(Name="first", Order=0)]
    public string First;
    [DataMember(Name="last", Order=1)]
    public string Last;
    /// <summary>
    /// private 필드도 serialize 할 수 있다.
    /// </summary>
    [DataMember(IsRequired=false, Order=2)]
    private string id;    
}

/// <summary>
/// 파라미터 목록과 리턴 타입은 항상 SOAP 요청/응답의 BODY에 맵핑된다. 
/// HEADER가 사용해야 할 필요가 있는 경우, MessageContract를 이용해 어떤 필드가 HEADER/BODY에 맵핑될지를 정의할 수 있다.
/// </summary>
//[MessageContract]
//public class EchoPersonMessage
//{
//    [MessageBody]
//    public Person Person;
//    [MessageHeader]
//    public Authorization Authorization;
//}



