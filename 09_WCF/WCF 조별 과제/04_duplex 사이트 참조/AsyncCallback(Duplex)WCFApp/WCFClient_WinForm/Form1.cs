using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WCFClient_WinForm
{
 

    public partial class Form1 : Form
    {
       

        public Form1()
        {
            InitializeComponent();
        }

        private void btnCallHTTP_Click(object sender, EventArgs e)
        {
            //CallService("httpEndPoint");
        }

        private void btnCallTCP_Click(object sender, EventArgs e)
        {
            CallService("tcpEndPoint");
        }

        private void btnCallNAMEDPIPE_Click(object sender, EventArgs e)
        {
            CallService("namedPipeEndPoint");
        }

        EchoServiceClient client = null;
        private string currentClientEndpointName = string.Empty;
        System.ServiceModel.InstanceContext site = new System.ServiceModel.InstanceContext(new EchoServiceCallbackHandler());

        private void CallService(string endpointConfName)
        {
            try
            {
                //System.Xml.XmlDocument dom = new System.Xml.XmlDocument();
                //dom.Load(string.Concat(System.Reflection.Assembly.GetExecutingAssembly().Location, ".config"));

                //System.Xml.XmlNode node = dom.SelectSingleNode("configuration/system.serviceModel/host/baseAddresses");


                if (client == null || endpointConfName != currentClientEndpointName)
                {                    
                    client = new EchoServiceClient(site, endpointConfName);
                    currentClientEndpointName = endpointConfName;
                }
               
                this.txtStatus.Text += String.Format("Connected...{0}\r\n", client.Endpoint.Address.Uri.AbsoluteUri);

                // invoke service operation
                this.txtStatus.Text += String.Format("Invoking endpoint: {0}\r\n",
                    client.Echo("Duck Chang Park"));

                
                xdndcpark.WCF.person.Person oPerson = new xdndcpark.WCF.person.Person();
                oPerson.first = "duck chang";
                oPerson.last = "park";

                oPerson = client.EchoPerson(oPerson);
                this.txtStatus.Text += String.Format("Invoking endpoint: {0}, {1}\r\n",
                    oPerson.first, oPerson.last);
               
            }
            catch (Exception ex)
            {
               MessageBox.Show(ex.ToString());
            }
            finally
            {                
                this.txtStatus.Text += String.Format("--------------------------------------\r\n");
            }
        }
       
        //구성정보 없이 코드로 Endpoint 구성후 호출
        private void CallServiceWithoutConfig()
        {
            try
            {
		    
            // 1. 클라이언트 상에 서비스 endpoint 정의하기
            System.ServiceModel.Description.ServiceEndpoint httpEndpoint = new System.ServiceModel.Description.ServiceEndpoint(
                System.ServiceModel.Description.ContractDescription.GetContract(
                   typeof(IEchoService)),new System.ServiceModel.WSHttpBinding(),
                new System.ServiceModel.EndpointAddress("http://xdn-dcpark/Server_Console/EchoService"));
 
            System.ServiceModel.Description.ServiceEndpoint tcpEndpoint= new System.ServiceModel.Description.ServiceEndpoint(
                System.ServiceModel.Description.ContractDescription.GetContract(
                   typeof(IEchoService)),
                new System.ServiceModel.NetTcpBinding(), 
                new System.ServiceModel.EndpointAddress("net.tcp://xdn-dcpark:20000/Server_Console/EchoService"));

            System.ServiceModel.Description.ServiceEndpoint namedPipeEndpoint= new System.ServiceModel.Description.ServiceEndpoint(
                System.ServiceModel.Description.ContractDescription.GetContract(
                   typeof(IEchoService)),
                new System.ServiceModel.NetNamedPipeBinding(), 
                new System.ServiceModel.EndpointAddress("net.pipe://xdn-dcpark/Server_Console/EchoService"));
 
            IEchoService svc = null;
 
            
		    // 2. Endpoint 에 기반한 Channel Factory 생성
            using (System.ServiceModel.ChannelFactory<IEchoService> httpFactory = 
                new System.ServiceModel.ChannelFactory<IEchoService>(httpEndpoint))
            {
		        // 3. Endpoint에 대한 Chennel proxy 생성
                svc = httpFactory.CreateChannel();

		        // 4. 서비스 오퍼레이션 호출
                this.txtStatus.Text += String.Format("Invoking HTTP endpoint(ONLY CODE): {0}\r\n", svc.Echo("Duck Chang Park"));
            }
             // 2. Endpoint 에 기반한 Channel Factory 생성
            using (System.ServiceModel.ChannelFactory<IEchoService> tcpFactory = 
                new System.ServiceModel.ChannelFactory<IEchoService>(tcpEndpoint))
            {
		        // 3. Endpoint에 대한 Chennel proxy 생성
                svc = tcpFactory.CreateChannel();

		        // 4. 서비스 오퍼레이션 호출
                this.txtStatus.Text += String.Format("Invoking TCP endpoint(ONLY CODE): {0}\r\n", svc.Echo("Duck Chang Park"));
            }
             // 2. Endpoint 에 기반한 Channel Factory 생성
            using (System.ServiceModel.ChannelFactory<IEchoService> namedPipeFactory = 
                new System.ServiceModel.ChannelFactory<IEchoService>(namedPipeEndpoint))
            {
		        // 3. Endpoint에 대한 Chennel proxy 생성
                svc = namedPipeFactory.CreateChannel();

		        // 4. 서비스 오퍼레이션 호출
                this.txtStatus.Text += String.Format("Invoking NAMED PIPE endpoint(ONLY CODE): {0}\r\n", svc.Echo("Duck Chang Park"));
            }
        
            }
        
            catch (Exception ex)
            {
               MessageBox.Show(ex.ToString());
            }
            finally
            {
              this.txtStatus.Text += String.Format("--------------------------------------\r\n");
           }
        }

        private void btnCallManual_Click(object sender, EventArgs e)
        {
            this.CallServiceWithoutConfig();
        }

        //전역 클라이언트 프록시 객체 변수
        internal EchoServiceClient asyncClient = null;
        
        private void btnCallHttpDual_Click(object sender, EventArgs e)
        {
            try
            {
                System.ServiceModel.InstanceContext site = new System.ServiceModel.InstanceContext(new EchoServiceCallbackHandler());

                asyncClient = new EchoServiceClient(site, "dualHttpEndPoint");

                this.txtStatus.Text += String.Format("Connected...{0}\r\n", asyncClient.Endpoint.Address.Uri.AbsoluteUri);

                

                // invoke service operation
                this.txtStatus.Text += String.Format("Invoking Duplex endpoint: AsyncEchoJob1\r\n");

                asyncClient.EchoJobStart("AsyncEchoJob1");
            }
            catch (TimeoutException timeProblem)
            {
                this.txtStatus.Text += String.Format("The service operation timed out....{0}\r\n", timeProblem.Message);
                asyncClient.Abort();                   
            }
            catch (System.ServiceModel.CommunicationException commProblem)
            {
                this.txtStatus.Text += String.Format("There was a communication problem....{0}\r\n", commProblem.Message);
                asyncClient.Abort();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            finally
            {                
                this.txtStatus.Text += String.Format("--------------------------------------\r\n");
            }   
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.txtStatus.Text = string.Empty;
        }
    }

    public class EchoServiceCallbackHandler : IEchoServiceCallback
    {
        public void EchoJobEnd(string result)
        {
            try
            {
                WCFClient_WinForm.Program.formInstance.txtStatus.Text += String.Format("callback called: {0}\r\n",
                       result);

                if (WCFClient_WinForm.Program.formInstance.asyncClient.State == System.ServiceModel.CommunicationState.Opened)
                    WCFClient_WinForm.Program.formInstance.asyncClient.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            finally
            {                
                WCFClient_WinForm.Program.formInstance.txtStatus.Text += String.Format("--------------------------------------\r\n");
            }

        }
    }  
}