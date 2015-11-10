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
using System.Xml;

namespace BindingSourceDemo
{
    /// <summary>
    /// Window4.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window4 : Window
    {
        public Window4()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window4_Loaded);
        }

        void Window4_Loaded(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();
            XmlDocument document = new XmlDocument();
            document.Load("Books.Xml");

            XmlNodeList nodeList;
            XmlNode root = document.DocumentElement;

            nodeList = root.SelectNodes("descendant::Book");
            myCanvas.DataContext = nodeList;
        }
    }
}
