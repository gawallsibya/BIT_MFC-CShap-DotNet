﻿//------------------------------------------------------------------------------
// <auto-generated>
//     이 코드는 도구를 사용하여 생성되었습니다.
//     런타임 버전:4.0.30319.18034
//
//     파일 내용을 변경하면 잘못된 동작이 발생할 수 있으며, 코드를 다시 생성하면
//     이러한 변경 내용이 손실됩니다.
// </auto-generated>
//------------------------------------------------------------------------------

namespace CALCULATE.ServiceReference1 {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="ServiceReference1.ICal", CallbackContract=typeof(CALCULATE.ServiceReference1.ICalCallback), SessionMode=System.ServiceModel.SessionMode.Required)]
    public interface ICal {
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Add")]
        void Add(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Add")]
        System.Threading.Tasks.Task AddAsync(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Sub")]
        void Sub(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Sub")]
        System.Threading.Tasks.Task SubAsync(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Div")]
        void Div(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Div")]
        System.Threading.Tasks.Task DivAsync(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Mul")]
        void Mul(int num1, int num2);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Mul")]
        System.Threading.Tasks.Task MulAsync(int num1, int num2);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface ICalCallback {
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/ICal/Result")]
        void Result([System.ServiceModel.MessageParameterAttribute(Name="result")] float result1);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface ICalChannel : CALCULATE.ServiceReference1.ICal, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class CalClient : System.ServiceModel.DuplexClientBase<CALCULATE.ServiceReference1.ICal>, CALCULATE.ServiceReference1.ICal {
        
        public CalClient(System.ServiceModel.InstanceContext callbackInstance) : 
                base(callbackInstance) {
        }
        
        public CalClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName) : 
                base(callbackInstance, endpointConfigurationName) {
        }
        
        public CalClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName, string remoteAddress) : 
                base(callbackInstance, endpointConfigurationName, remoteAddress) {
        }
        
        public CalClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(callbackInstance, endpointConfigurationName, remoteAddress) {
        }
        
        public CalClient(System.ServiceModel.InstanceContext callbackInstance, System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(callbackInstance, binding, remoteAddress) {
        }
        
        public void Add(int num1, int num2) {
            base.Channel.Add(num1, num2);
        }
        
        public System.Threading.Tasks.Task AddAsync(int num1, int num2) {
            return base.Channel.AddAsync(num1, num2);
        }
        
        public void Sub(int num1, int num2) {
            base.Channel.Sub(num1, num2);
        }
        
        public System.Threading.Tasks.Task SubAsync(int num1, int num2) {
            return base.Channel.SubAsync(num1, num2);
        }
        
        public void Div(int num1, int num2) {
            base.Channel.Div(num1, num2);
        }
        
        public System.Threading.Tasks.Task DivAsync(int num1, int num2) {
            return base.Channel.DivAsync(num1, num2);
        }
        
        public void Mul(int num1, int num2) {
            base.Channel.Mul(num1, num2);
        }
        
        public System.Threading.Tasks.Task MulAsync(int num1, int num2) {
            return base.Channel.MulAsync(num1, num2);
        }
    }
}
