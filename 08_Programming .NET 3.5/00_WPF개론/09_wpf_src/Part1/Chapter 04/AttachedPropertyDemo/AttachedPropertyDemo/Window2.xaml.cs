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

namespace AttachedPropertyDemo
{
    /// <summary>
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window2_Loaded);
        }

        void Window2_Loaded(object sender, RoutedEventArgs e)
        {
           NameFactory.SetCallName(txt,"I am TextBox");
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string callName = NameFactory.GetCallName(txt);
            txt.Text = callName;
        }
    }
}
