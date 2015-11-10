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

namespace PrintingDemo
{
    /// <summary>
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
            
        }

        private void btnPrint_Click(object sender, RoutedEventArgs e)
        {
            FlowDocument flowDocument = flowDocumentReader.Document;
            PrintDialog printDialog = new PrintDialog();
            printDialog.UserPageRangeEnabled = true;
            
            
            if (printDialog.ShowDialog() == true)
            {
                for (int i = printDialog.PageRange.PageFrom; i <= printDialog.PageRange.PageTo; i++)
                {

                    DocumentPage dp =
                    (flowDocument as IDocumentPaginatorSource).DocumentPaginator.GetPage(i);
                    printDialog.PrintVisual(dp.Visual, "desc");
                }
            }

            

            //printDialog.PrintDocument((flowDocument as    
            //       IDocumentPaginatorSource).DocumentPaginator,
            //     "flowDocument");

            
        }

             
    }
}
