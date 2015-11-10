using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using BindingSourceDemo.MyWebService;

namespace BindingSourceDemo
{
    /// <summary>
    /// Window5.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window5 : Window
    {
        public Window5()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window5_Loaded);
        }

        void Window5_Loaded(object sender, RoutedEventArgs e)
        {
            MyWebService.MyServiceSoapClient myservice = new MyServiceSoapClient();
            ArrayOfString names=myservice.GetNames();
            lBox.ItemsSource = names;
            //throw new NotImplementedException();
        }
    }
}
