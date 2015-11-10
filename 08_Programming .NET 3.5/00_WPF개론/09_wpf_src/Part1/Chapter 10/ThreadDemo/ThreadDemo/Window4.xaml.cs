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
using System.Windows.Threading;
using System.Threading;

namespace ThreadDemo
{
    /// <summary>
    /// Window4.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window4 : Window
    {
        DispatcherTimer dtimer;
        Timer timer;
        public Window4()
        {
            InitializeComponent();
        }
        
        public void CallBackTimer(object sender)
        {
            btnTimer.Content = System.DateTime.Now.ToString();
        }
       
        public void CallBackHandler(object sender, EventArgs e)
        {
            btnDispatcherTimer.Content = System.DateTime.Now.ToString();
        }

        private void btnTimer_Click(object sender, RoutedEventArgs e)
        {
            timer=new Timer(CallBackTimer,null,0,10000);
        }

        private void btnDispatcherTimer_Click(object sender, RoutedEventArgs e)
        {
            dtimer = new DispatcherTimer(new TimeSpan(0, 0, 1), DispatcherPriority.SystemIdle, CallBackHandler, btnDispatcherTimer.Dispatcher);
        }
    }
}
