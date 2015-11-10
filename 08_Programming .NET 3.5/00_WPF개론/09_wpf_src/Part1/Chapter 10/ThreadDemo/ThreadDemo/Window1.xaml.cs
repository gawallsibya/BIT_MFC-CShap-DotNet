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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using System.Windows.Forms;
namespace ThreadDemo
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        delegate void delRun();
        public Window1()
        {
            InitializeComponent();
        }

        private void btnBeforeWPF_Click(object sender, RoutedEventArgs e)
        {
            ThreadStart ts = new ThreadStart(Change);
            Thread thread = new Thread(ts);
            thread.Start();

        }

        void Change()
        {
           btnBeforeWPF.Content = "Yes?";
           
            
        }


        private void btnWPF_Click(object sender, RoutedEventArgs e)
        {
            btnWPF.Dispatcher.Invoke(new delRun(Change2));
        }
        void Change2()
        {
            btnWPF.Content = "Yes";
            
        }

        private void btnAccesCheck_Click(object sender, RoutedEventArgs e)
        {
            if (btnWPF.Dispatcher.CheckAccess())
            {
                System.Windows.Forms.MessageBox.Show("Access Possible");
            }
        }

        
    }
}
