using System;
using System.Collections.Generic;
using System.Text;
using System.ServiceModel;

namespace Server_Console
{
    class Program
    {
        static void Main(string[] args)
        {
            StartService();
        }

        internal static ServiceHost myServiceHost = null;

        internal static void StartService()
        {
            try
            {
                // Consider putting the baseAddress in the configuration system
                // and getting it here with AppSettings
                //Uri baseAddress = new Uri("net.tcp://localhost:8080/Server_Console/EchoService");

                // Instantiate new ServiceHost 
                using (myServiceHost = new ServiceHost(typeof(EchoService)))//, baseAddress);
                {
                    myServiceHost.Open();

                    //현재의 Endpoint 목록 표시하기
                    Console.WriteLine("{0} is open and has the following endpoints:\n", myServiceHost.Description.ServiceType);

                    //현재의 Endpoint들의 정보목록(Address, Binding, Contract) 표시하기
                    int i = 1;
                    foreach (System.ServiceModel.Description.ServiceEndpoint end in myServiceHost.Description.Endpoints)
                    {
                        Console.WriteLine("Endpoint #{0}", i++);
                        Console.WriteLine("Address: {0}", end.Address.Uri.AbsoluteUri);
                        Console.WriteLine("Binding: {0}", end.Binding.Name);
                        Console.WriteLine("Contract: {0}\n", end.Contract.Name);
                    }

                    //현재 Endpoint에 해당하는 Listener 목록 표시하기
                    Console.WriteLine("The following EndpointListeners are active:\n");
                    foreach (System.ServiceModel.Dispatcher.ChannelDispatcher c in myServiceHost.ChannelDispatchers)
                        Console.WriteLine(c.Listener.Uri.AbsoluteUri);


                    Console.WriteLine("종료하시려면 엔터키를 누르세요");
                    Console.ReadLine();
                }
            }
            catch (Exception ex)
            {
                Console.Write(ex.ToString());
                Console.Read();
                
            }
        }
        //internal static void StopService()
        //{
        //    // Call StopService from your shutdown logic (i.e. dispose method)
        //    if (myServiceHost.State != CommunicationState.Closed)
        //        myServiceHost.Close();
        //}
    }
}
