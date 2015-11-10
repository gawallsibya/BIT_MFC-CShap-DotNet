using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Callback_예제
{
    class Program
    {
        static void Main(string[] args)
        {
            TestClass t = new TestClass(new Service());
            string str = "";
            while (str != "0")
            {
               str = Console.ReadLine();
               t.PerformTask();
            }
        }
    }
    public interface IService
    {
        void DoSomething();
    }

    public class Service : IService
    {
        public void DoSomething()
        {
            Console.WriteLine("Doing something");
        }
    }
    public class TestClass 
    {
        private readonly IService service;
        private delegate void TestDelegate();

        public TestClass(IService service)
        {
            this.service = service;
        }

        public void PerformTask()
        {
            var testDelegate = new TestDelegate(service.DoSomething);
            testDelegate.BeginInvoke(TestCallback, null);
        }
        private void TestCallback(IAsyncResult result)
        {
            var asyncResult = (System.Runtime.Remoting.Messaging.AsyncResult)result;
            var testDelegate = (TestDelegate)asyncResult.AsyncDelegate;
            testDelegate.EndInvoke(result);
            Thread.Sleep(3000);
            Console.WriteLine("OK");
        }
    }
}
