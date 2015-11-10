using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Media.Animation;
using System.Threading;

namespace ThreadDemo
{
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
            delegate void DelRun();
    delegate void DelUpdateUI(string msg);
    DelRun delRun;
    DelUpdateUI delUpdateUI;
    bool running = false;
    Storyboard sb;
    public Window3()
    {
       InitializeComponent();
       delRun = new DelRun(Run);
       delUpdateUI = new DelUpdateUI(UpdateUI);
       sb = (Storyboard)Resources["myAni"];
    }

     private void StartOrStop_Click(object sender, RoutedEventArgs e)
     {
         if (!running)
         {
            delRun.BeginInvoke(null, null);
            sb.Begin();
            running = true;
        }
       else {
            sb.Stop();
            StartOrStop.Content = "Start";
            txState.Text  = "Not Connected....";
            running = false;
        }
    }
     private void Run()
     {
        Random rnd = new Random();
        int interval = rnd.Next(1000, 10000);
        txState.Dispatcher.BeginInvoke(delUpdateUI, "Waiting.....");
        Thread.Sleep(interval);
        txState.Dispatcher.BeginInvoke(delUpdateUI, "Conntected.....");
    }

    private void UpdateUI(string msg)
    {
       if (msg == "Waiting.....")
       {
           StartOrStop.Content = "Waiting.....";
           StartOrStop.IsEnabled = false;
            txState.Text = msg;
       }
       else if (msg == "Conntected.....")
       {
         StartOrStop.Content = "Stop";
           StartOrStop.IsEnabled = true;
           txState.Text = msg;
       }
     
   }

 }
}
