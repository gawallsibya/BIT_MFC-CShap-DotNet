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
using System.Windows.Xps;
using System.IO;
using System.IO.Packaging;
using System.Xml;
using System.Windows.Annotations;
using System.Windows.Annotations.Storage;

namespace AnnotationDemo
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        AnnotationService ans;
        FileStream fs;
        public Window1()
        {
            InitializeComponent();
            Loaded+=new RoutedEventHandler(Window1_Loaded);
        }

        

        void Window1_Loaded(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();

            XpsDocument xd =
            new XpsDocument("annotation.xps", System.IO.FileAccess.ReadWrite);
            dv.Document = xd.GetFixedDocumentSequence();

            ans = new AnnotationService(dv);
            
            fs=            
            new FileStream(
                         "annotation.dat", FileMode.OpenOrCreate, FileAccess.ReadWrite);
           

            ans.Enable(new XmlStreamStore(fs));
            ans.Store.AutoFlush = true;
            
            


        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            AnnotationDocumentPaginator paginator = new AnnotationDocumentPaginator(dv.Document.DocumentPaginator, ans.Store);
            PrintDialog pd = new PrintDialog();
            pd.PrintDocument(paginator, "annotiationPrint");
        }
    }
}
