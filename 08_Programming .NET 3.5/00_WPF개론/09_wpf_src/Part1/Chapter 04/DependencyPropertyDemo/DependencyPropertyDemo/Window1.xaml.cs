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

namespace DependencyPropertyDemo
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Animal ani = myPanel.Resources["myAni"] as Animal;
            ani.AniName = "Lion";

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
           // Window2 win2 = new Window2();
            //win2.Show();
        }
    }
}
