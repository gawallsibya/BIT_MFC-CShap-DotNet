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
namespace DocumentDemo
{
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        private void btnXmlWriter_Click(object sender, RoutedEventArgs e)
        {
            using (XpsDocument xpsDoc = new XpsDocument("Out.xps", FileAccess.Write))
            {
                IXpsFixedDocumentSequenceWriter sequenceWriter =
                xpsDoc.AddFixedDocumentSequence();
                IXpsFixedDocumentWriter docWriter =
                sequenceWriter.AddFixedDocument();
                IXpsFixedPageWriter pageWriter = docWriter.AddFixedPage();
                XmlWriter xmlWriter = pageWriter.XmlWriter;
                xmlWriter.WriteStartElement("FixedPage");
                xmlWriter.WriteAttributeString("xmlns",
                             "http://schemas.microsoft.com/xps/2005/06");
                xmlWriter.WriteAttributeString("Width", "600");
                xmlWriter.WriteAttributeString("Height", "400");
                xmlWriter.WriteAttributeString("xml:lang", "ko-KR");
                xmlWriter.WriteStartElement("Path");
                xmlWriter.WriteAttributeString("Data",
                                    "M 10,10 L 150,200 500,300 555,387 z");
                xmlWriter.WriteAttributeString("Fill", "#ffff0000");
                xmlWriter.WriteEndElement();
                xmlWriter.WriteEndElement();
                pageWriter.Commit();
                docWriter.Commit();
                sequenceWriter.Commit();
            }


        }

        private void btnXpsDocumentWriter_Click(object sender, RoutedEventArgs e)
        {
            using (Package xpsPackage = Package.Open("Out.xps", FileMode.Create,
                           FileAccess.ReadWrite))
            using (XpsDocument doc = new XpsDocument(xpsPackage))
            {

                FixedPage page = new FixedPage();
                Canvas canvas = new Canvas();
                canvas.Width = 600;
                canvas.Height = 400;
                page.Children.Add(canvas);
                Rectangle rect = new Rectangle();
                Canvas.SetLeft(rect, 50);
                Canvas.SetTop(rect, 50);
                rect.Width = 200;
                rect.Height = 100;
                rect.Stroke = Brushes.Black;
                rect.StrokeThickness = 1;
                canvas.Children.Add(rect);
                XpsDocumentWriter documentWriter = 
                XpsDocument.CreateXpsDocumentWriter(doc);
                documentWriter.Write(page);

                doc.CoreDocumentProperties.Description = "Rectangle Output";
            }


        }
    }
}
