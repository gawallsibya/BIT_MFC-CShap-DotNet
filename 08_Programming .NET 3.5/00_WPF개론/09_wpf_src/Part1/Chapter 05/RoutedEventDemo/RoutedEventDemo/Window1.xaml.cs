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

namespace RoutedEventDemo
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void btnClickMe_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("btnClickMe_Click");
        }

        private void childCanvas_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("childCanvas_Click");
        }

        private void parentCanvas_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("parentCanvas_Click");
        }
    }
}
