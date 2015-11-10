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

namespace LayoutDemo
{
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window3_Loaded);
        }

        void Window3_Loaded(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();

        }
    }
}
