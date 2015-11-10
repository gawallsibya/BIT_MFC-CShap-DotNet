using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace Sample
{
     public class CCal : ICal
     {
         private float m_result;
         private ICallback callback = null;
         public CCal()
         {
             callback = OperationContext.Current.GetCallbackChannel<ICallback>();
         }

         public void Add(int num1, int num2) { m_result = num1 + num2; callback.Result(m_result); }
         public void Sub(int num1, int num2) { m_result = num1 + num2; callback.Result(m_result); }
         public void Mul(int num1, int num2) { m_result = num1 * num2; callback.Result(m_result); }
         public void Div(int num1, int num2) { m_result = (float)num1 / num2; callback.Result(m_result); }
    }
}
