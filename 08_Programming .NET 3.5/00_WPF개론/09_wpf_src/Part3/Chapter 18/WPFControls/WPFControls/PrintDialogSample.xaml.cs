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
using System.IO;

namespace WPFControls
{
    /// <summary>
    /// PrintDialogSample.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class PrintDialogSample : Window
    {
        public PrintDialogSample()
        {
            InitializeComponent();
        }

   

        private void btnPrintInvoke_Click(object sender, RoutedEventArgs e)
        {
            PrintDialog pDialog = new PrintDialog();
            pDialog.PageRangeSelection = PageRangeSelection.AllPages;
            pDialog.UserPageRangeEnabled = true;

            Nullable<Boolean> print = pDialog.ShowDialog();
            if (print == true)
            {
                XpsDocument xpsDocument = new XpsDocument("Entity.xps", FileAccess.ReadWrite);
                FixedDocumentSequence fixedDocSeq = xpsDocument.GetFixedDocumentSequence();
                pDialog.PrintDocument(fixedDocSeq.DocumentPaginator, "Test print job");
            }
        }
    }
}
