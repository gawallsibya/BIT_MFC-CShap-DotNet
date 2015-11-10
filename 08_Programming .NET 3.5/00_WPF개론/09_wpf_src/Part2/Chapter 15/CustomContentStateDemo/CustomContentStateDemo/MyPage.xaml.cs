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

namespace CustomContentStateDemo
{
    /// <summary>
    /// MyPage.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MyPage : Page
    {
        public MyPage()
        {
            InitializeComponent();
        }

        private void btnAddBackEntry_Click(object sender, RoutedEventArgs e)
        {
            MyCustomContentState mc = new MyCustomContentState(textIrum, textJuso);
            NavigationService.AddBackEntry(mc);
        }
    }
}
