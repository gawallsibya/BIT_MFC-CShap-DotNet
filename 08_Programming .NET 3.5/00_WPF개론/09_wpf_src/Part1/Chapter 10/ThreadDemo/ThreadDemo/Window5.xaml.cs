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

namespace ThreadDemo
{
    /// <summary>
    /// Window5.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window5 : Window
    {
        public Window5()
        {
            InitializeComponent();
        }

        private void callCompoButton_Click(object sender, RoutedEventArgs e)
        {
            Demo demo = new Demo(this);
            string id =
             System.Threading.Thread.CurrentThread.ManagedThreadId.ToString();

            MessageBox.Show(id);
               
            demo.Do();
            
        }
    }
}
