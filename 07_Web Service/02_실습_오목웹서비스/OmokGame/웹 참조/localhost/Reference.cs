﻿//------------------------------------------------------------------------------
// <auto-generated>
//     이 코드는 도구를 사용하여 생성되었습니다.
//     런타임 버전:4.0.30319.42000
//
//     파일 내용을 변경하면 잘못된 동작이 발생할 수 있으며, 코드를 다시 생성하면
//     이러한 변경 내용이 손실됩니다.
// </auto-generated>
//------------------------------------------------------------------------------

// 
// 이 소스 코드가 Microsoft.VSDesigner, 버전 4.0.30319.42000에서 자동으로 생성되었습니다.
// 
#pragma warning disable 1591

namespace OmokGame.localhost {
    using System;
    using System.Web.Services;
    using System.Diagnostics;
    using System.Web.Services.Protocols;
    using System.Xml.Serialization;
    using System.ComponentModel;
    
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.81.0")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Web.Services.WebServiceBindingAttribute(Name="Service1Soap", Namespace="http://tempuri.org/")]
    public partial class Service1 : System.Web.Services.Protocols.SoapHttpClientProtocol {
        
        private System.Threading.SendOrPostCallback GetBestJumOperationCompleted;
        
        private System.Threading.SendOrPostCallback CheckChakJumOperationCompleted;
        
        private bool useDefaultCredentialsSetExplicitly;
        
        /// <remarks/>
        public Service1() {
            this.Url = "http://localhost/OmokAIService/Service1.asmx";
            if ((this.IsLocalFileSystemWebService(this.Url) == true)) {
                this.UseDefaultCredentials = true;
                this.useDefaultCredentialsSetExplicitly = false;
            }
            else {
                this.useDefaultCredentialsSetExplicitly = true;
            }
        }
        
        public new string Url {
            get {
                return base.Url;
            }
            set {
                if ((((this.IsLocalFileSystemWebService(base.Url) == true) 
                            && (this.useDefaultCredentialsSetExplicitly == false)) 
                            && (this.IsLocalFileSystemWebService(value) == false))) {
                    base.UseDefaultCredentials = false;
                }
                base.Url = value;
            }
        }
        
        public new bool UseDefaultCredentials {
            get {
                return base.UseDefaultCredentials;
            }
            set {
                base.UseDefaultCredentials = value;
                this.useDefaultCredentialsSetExplicitly = true;
            }
        }
        
        /// <remarks/>
        public event GetBestJumCompletedEventHandler GetBestJumCompleted;
        
        /// <remarks/>
        public event CheckChakJumCompletedEventHandler CheckChakJumCompleted;
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://tempuri.org/GetBestJum", RequestNamespace="http://tempuri.org/", ResponseNamespace="http://tempuri.org/", Use=System.Web.Services.Description.SoapBindingUse.Literal, ParameterStyle=System.Web.Services.Protocols.SoapParameterStyle.Wrapped)]
        public string GetBestJum(string strJums, int stone) {
            object[] results = this.Invoke("GetBestJum", new object[] {
                        strJums,
                        stone});
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public System.IAsyncResult BeginGetBestJum(string strJums, int stone, System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("GetBestJum", new object[] {
                        strJums,
                        stone}, callback, asyncState);
        }
        
        /// <remarks/>
        public string EndGetBestJum(System.IAsyncResult asyncResult) {
            object[] results = this.EndInvoke(asyncResult);
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public void GetBestJumAsync(string strJums, int stone) {
            this.GetBestJumAsync(strJums, stone, null);
        }
        
        /// <remarks/>
        public void GetBestJumAsync(string strJums, int stone, object userState) {
            if ((this.GetBestJumOperationCompleted == null)) {
                this.GetBestJumOperationCompleted = new System.Threading.SendOrPostCallback(this.OnGetBestJumOperationCompleted);
            }
            this.InvokeAsync("GetBestJum", new object[] {
                        strJums,
                        stone}, this.GetBestJumOperationCompleted, userState);
        }
        
        private void OnGetBestJumOperationCompleted(object arg) {
            if ((this.GetBestJumCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.GetBestJumCompleted(this, new GetBestJumCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://tempuri.org/CheckChakJum", RequestNamespace="http://tempuri.org/", ResponseNamespace="http://tempuri.org/", Use=System.Web.Services.Description.SoapBindingUse.Literal, ParameterStyle=System.Web.Services.Protocols.SoapParameterStyle.Wrapped)]
        public string CheckChakJum(string strJums, int x, int y, int stone) {
            object[] results = this.Invoke("CheckChakJum", new object[] {
                        strJums,
                        x,
                        y,
                        stone});
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public System.IAsyncResult BeginCheckChakJum(string strJums, int x, int y, int stone, System.AsyncCallback callback, object asyncState) {
            return this.BeginInvoke("CheckChakJum", new object[] {
                        strJums,
                        x,
                        y,
                        stone}, callback, asyncState);
        }
        
        /// <remarks/>
        public string EndCheckChakJum(System.IAsyncResult asyncResult) {
            object[] results = this.EndInvoke(asyncResult);
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public void CheckChakJumAsync(string strJums, int x, int y, int stone) {
            this.CheckChakJumAsync(strJums, x, y, stone, null);
        }
        
        /// <remarks/>
        public void CheckChakJumAsync(string strJums, int x, int y, int stone, object userState) {
            if ((this.CheckChakJumOperationCompleted == null)) {
                this.CheckChakJumOperationCompleted = new System.Threading.SendOrPostCallback(this.OnCheckChakJumOperationCompleted);
            }
            this.InvokeAsync("CheckChakJum", new object[] {
                        strJums,
                        x,
                        y,
                        stone}, this.CheckChakJumOperationCompleted, userState);
        }
        
        private void OnCheckChakJumOperationCompleted(object arg) {
            if ((this.CheckChakJumCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.CheckChakJumCompleted(this, new CheckChakJumCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        public new void CancelAsync(object userState) {
            base.CancelAsync(userState);
        }
        
        private bool IsLocalFileSystemWebService(string url) {
            if (((url == null) 
                        || (url == string.Empty))) {
                return false;
            }
            System.Uri wsUri = new System.Uri(url);
            if (((wsUri.Port >= 1024) 
                        && (string.Compare(wsUri.Host, "localHost", System.StringComparison.OrdinalIgnoreCase) == 0))) {
                return true;
            }
            return false;
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.81.0")]
    public delegate void GetBestJumCompletedEventHandler(object sender, GetBestJumCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.81.0")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class GetBestJumCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal GetBestJumCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public string Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((string)(this.results[0]));
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.81.0")]
    public delegate void CheckChakJumCompletedEventHandler(object sender, CheckChakJumCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.6.81.0")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class CheckChakJumCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal CheckChakJumCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public string Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((string)(this.results[0]));
            }
        }
    }
}

#pragma warning restore 1591