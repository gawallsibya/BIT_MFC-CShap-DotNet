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
using System.Windows.Xps.Packaging;


namespace DocumentDemo
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
            //throw new NotImplementedException();
            XpsDocument xpsdoc = new XpsDocument("xml.xps", System.IO.FileAccess.Read);
            FixedDocumentSequence fds = xpsdoc.GetFixedDocumentSequence();
            documentViewer.Document = fds.References[0].GetDocument(true);

            

        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {

        }
    }
}
