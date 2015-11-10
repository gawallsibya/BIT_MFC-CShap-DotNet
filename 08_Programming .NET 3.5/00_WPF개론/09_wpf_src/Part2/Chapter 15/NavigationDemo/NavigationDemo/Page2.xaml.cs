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

namespace NavigationDemo
{
    /// <summary>
    /// Page2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Page2 : Page
    {
        public Page2()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page2_Loaded);
            Unloaded += new RoutedEventHandler(Page2_Unloaded);
        }

        void Page2_Unloaded(object sender, RoutedEventArgs e)
        {

            //throw new NotImplementedException();
        }

        void Page2_Loaded(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigating += new NavigatingCancelEventHandler(NavigationService_Navigating);
            //throw new NotImplementedException();
        }

        void NavigationService_Navigating(object sender, NavigatingCancelEventArgs e)
        {
            //throw new NotImplementedException();
            btnNavigate.Content  = "loading...";
        }



        private void btnNavigate_Click(object sender, RoutedEventArgs e)
        {
            try
            {

                NavigationService.Navigate(new Uri(textAddress.Text));
            }
            catch 
            {

                textAddress.Text = "새로운 값을 입력 해 주세요";
            }
        }
    }
}
