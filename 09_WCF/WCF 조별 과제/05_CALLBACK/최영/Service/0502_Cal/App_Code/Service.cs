using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

//WCF 구성으로 이중 계약 바인딩 만드는 법
//구성 단계중 상호 운영성 패널에서
//고급 웹 서비스 상호 운용성 -> 이중 통신 체크
[ServiceContract(CallbackContract = typeof(ICalCallback))]
public interface ICal
{
    [OperationContract(IsOneWay=true)]
    void Add(int num1, int num2);

    [OperationContract(IsOneWay = true)]
    void Sub(int num1, int num2);

    [OperationContract(IsOneWay = true)]
    void Mul(int num1, int num2);

    [OperationContract(IsOneWay = true)]
    void Div(int num1, int num2);

    [OperationContract(IsOneWay = true)]
    void Clear();
}

public interface ICalCallback
{
    [OperationContract(IsOneWay=true)]
    void Result(float result);
}

// 참고: "리팩터링" 메뉴에서 "이름 바꾸기" 명령을 사용하여 코드, svc 및 config 파일에서 클래스 이름  "Service"를 변경할 수 있습니다.
public class Service : ICal
{
    private float m_result;
    ICalCallback callback = null;

    public float Result { get { return m_result; } }
    public Service()
    {
        m_result = 0.0f;
        callback = OperationContext.Current.GetCallbackChannel<ICalCallback>();
    }

    public void Add(int num1, int num2)
    {
        m_result = num1 + num2;
    }

    public void Sub(int num1, int num2)
    {
        m_result = num1 - num2;
    }

    public void Mul(int num1, int num2)
    {
        m_result = num1 * num2;
    }

    public void Div(int num1, int num2)
    {
        m_result = (float)num1 / num2;
        
    }

    public void Clear()
    {
        callback.Result(m_result);
    }
}
