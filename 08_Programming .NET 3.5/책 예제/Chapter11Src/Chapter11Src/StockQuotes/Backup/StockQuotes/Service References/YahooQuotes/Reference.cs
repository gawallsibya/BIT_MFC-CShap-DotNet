﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.1433
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace StockQuotes.YahooQuotes {
    using System.Runtime.Serialization;
    using System;
    
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Runtime.Serialization", "3.0.0.0")]
    [System.Runtime.Serialization.DataContractAttribute(Name="StockQuote", Namespace="http://schemas.datacontract.org/2004/07/")]
    [System.SerializableAttribute()]
    public partial class StockQuote : object, System.Runtime.Serialization.IExtensibleDataObject, System.ComponentModel.INotifyPropertyChanged {
        
        [System.NonSerializedAttribute()]
        private System.Runtime.Serialization.ExtensionDataObject extensionDataField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string ChangeField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string CompanyNameField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string DateOfTradeField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string DaysRangeField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string LastTradePriceField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string OpenField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string PercentageChangeField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string PreviousCloseField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string TimeOfTradeField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string VolumeField;
        
        [global::System.ComponentModel.BrowsableAttribute(false)]
        public System.Runtime.Serialization.ExtensionDataObject ExtensionData {
            get {
                return this.extensionDataField;
            }
            set {
                this.extensionDataField = value;
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string Change {
            get {
                return this.ChangeField;
            }
            set {
                if ((object.ReferenceEquals(this.ChangeField, value) != true)) {
                    this.ChangeField = value;
                    this.RaisePropertyChanged("Change");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string CompanyName {
            get {
                return this.CompanyNameField;
            }
            set {
                if ((object.ReferenceEquals(this.CompanyNameField, value) != true)) {
                    this.CompanyNameField = value;
                    this.RaisePropertyChanged("CompanyName");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string DateOfTrade {
            get {
                return this.DateOfTradeField;
            }
            set {
                if ((object.ReferenceEquals(this.DateOfTradeField, value) != true)) {
                    this.DateOfTradeField = value;
                    this.RaisePropertyChanged("DateOfTrade");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string DaysRange {
            get {
                return this.DaysRangeField;
            }
            set {
                if ((object.ReferenceEquals(this.DaysRangeField, value) != true)) {
                    this.DaysRangeField = value;
                    this.RaisePropertyChanged("DaysRange");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string LastTradePrice {
            get {
                return this.LastTradePriceField;
            }
            set {
                if ((object.ReferenceEquals(this.LastTradePriceField, value) != true)) {
                    this.LastTradePriceField = value;
                    this.RaisePropertyChanged("LastTradePrice");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string Open {
            get {
                return this.OpenField;
            }
            set {
                if ((object.ReferenceEquals(this.OpenField, value) != true)) {
                    this.OpenField = value;
                    this.RaisePropertyChanged("Open");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string PercentageChange {
            get {
                return this.PercentageChangeField;
            }
            set {
                if ((object.ReferenceEquals(this.PercentageChangeField, value) != true)) {
                    this.PercentageChangeField = value;
                    this.RaisePropertyChanged("PercentageChange");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string PreviousClose {
            get {
                return this.PreviousCloseField;
            }
            set {
                if ((object.ReferenceEquals(this.PreviousCloseField, value) != true)) {
                    this.PreviousCloseField = value;
                    this.RaisePropertyChanged("PreviousClose");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string TimeOfTrade {
            get {
                return this.TimeOfTradeField;
            }
            set {
                if ((object.ReferenceEquals(this.TimeOfTradeField, value) != true)) {
                    this.TimeOfTradeField = value;
                    this.RaisePropertyChanged("TimeOfTrade");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string Volume {
            get {
                return this.VolumeField;
            }
            set {
                if ((object.ReferenceEquals(this.VolumeField, value) != true)) {
                    this.VolumeField = value;
                    this.RaisePropertyChanged("Volume");
                }
            }
        }
        
        public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;
        
        protected void RaisePropertyChanged(string propertyName) {
            System.ComponentModel.PropertyChangedEventHandler propertyChanged = this.PropertyChanged;
            if ((propertyChanged != null)) {
                propertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
            }
        }
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "3.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="YahooQuotes.IYahooQuotes")]
    public interface IYahooQuotes {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IYahooQuotes/TestService", ReplyAction="http://tempuri.org/IYahooQuotes/TestServiceResponse")]
        string TestService(int intParam);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IYahooQuotes/GetQuoteForStockSymbol", ReplyAction="http://tempuri.org/IYahooQuotes/GetQuoteForStockSymbolResponse")]
        StockQuotes.YahooQuotes.StockQuote GetQuoteForStockSymbol(string aSymbol);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "3.0.0.0")]
    public interface IYahooQuotesChannel : StockQuotes.YahooQuotes.IYahooQuotes, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "3.0.0.0")]
    public partial class YahooQuotesClient : System.ServiceModel.ClientBase<StockQuotes.YahooQuotes.IYahooQuotes>, StockQuotes.YahooQuotes.IYahooQuotes {
        
        public YahooQuotesClient() {
        }
        
        public YahooQuotesClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public YahooQuotesClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public YahooQuotesClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public YahooQuotesClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public string TestService(int intParam) {
            return base.Channel.TestService(intParam);
        }
        
        public StockQuotes.YahooQuotes.StockQuote GetQuoteForStockSymbol(string aSymbol) {
            return base.Channel.GetQuoteForStockSymbol(aSymbol);
        }
    }
}
