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

namespace ThreadDemo
{
    /// <summary>
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
        delegate void delRun();
        bool running = false;
        double startNum = 0;

        public Window2()
        {
            InitializeComponent();
        }

        

        private void StartOrStop_Click(object sender, RoutedEventArgs e)
        {
            if (!running)
            {
                running = true;
                StartOrStop.Content = "Stop";
                StartOrStop.Dispatcher.BeginInvoke(new delRun(DisplayNum), 
                                          DispatcherPriority.Normal);
            }
            else
             {
                 running = false;
                 StartOrStop.Content = "Resume";
            }
        }

        void DisplayNum()
        {
            if (running)
             {
                 lblNum.Content = startNum++.ToString();
                 StartOrStop.Dispatcher.BeginInvoke(new delRun(DisplayNum),
                                         DispatcherPriority.SystemIdle);
             }
        }
    }

}
    

