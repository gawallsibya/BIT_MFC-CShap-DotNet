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
using System.Windows.Xps.Packaging;

namespace WPFControls
{
    /// <summary>
    /// DocumentViwerSample.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class DocumentViwerSample : Window
    {
        public DocumentViwerSample()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(DocumentViwerSample_Loaded);
          
        }

        void DocumentViwerSample_Loaded(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();
            

              XpsDocument xpsdoc = new XpsDocument("entity.xps", System.IO.FileAccess.Read);
              FixedDocumentSequence fds = xpsdoc.GetFixedDocumentSequence();
              dockViewer.Document= fds.References[0].GetDocument(true);

        }

        
    }
}
