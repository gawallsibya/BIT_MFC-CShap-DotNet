using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using System.Windows.Forms;
using System.Windows.Threading;


namespace ThreadDemo
{
    class Demo
    {
        System.Windows.Window window;
        public Demo(System.Windows.Window window)
        {
            this.window = window;
        }
        public void Do()
        {
            DispatcherSynchronizationContext requestingContext =
               (DispatcherSynchronizationContext)DispatcherSynchronizationContext.Current;

            SendOrPostCallback callback = new SendOrPostCallback(DoEvent);
            requestingContext.Post(callback, null);
            requestingContext = null;
           
            
        }

        private void DoEvent(object e)
        {
            string id =
             System.Threading.Thread.CurrentThread.ManagedThreadId.ToString();

            System.Windows.Forms.MessageBox.Show(id);
               
        }

       

    }
}
