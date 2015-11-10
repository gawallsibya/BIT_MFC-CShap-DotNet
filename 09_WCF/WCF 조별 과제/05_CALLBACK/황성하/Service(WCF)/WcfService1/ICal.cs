using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace WcfService1
{
    [ServiceContract(SessionMode = SessionMode.Required, CallbackContract = typeof(ICallback))]
    public interface ICal
    {
        [OperationContract(IsOneWay = true)]
        void Add(int num1, int num2);
        [OperationContract(IsOneWay = true)]
        void Sub(int num1, int num2);
        [OperationContract(IsOneWay = true)]
        void Div(int num1, int num2);
        [OperationContract(IsOneWay = true)]
        void Mul(int num1, int num2);
    }

    public interface ICallback
    {
        [OperationContract(IsOneWay = true)]
        void Result(float result);
    }

   
}
