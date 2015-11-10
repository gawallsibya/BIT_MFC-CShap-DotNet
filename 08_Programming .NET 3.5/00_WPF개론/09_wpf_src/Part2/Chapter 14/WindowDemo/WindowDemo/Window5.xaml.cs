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
using System.IO;

namespace WindowDemo
{
    /// <summary>
    /// Window5.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window5 : Window
    {
        public Window5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog
                = new Microsoft.Win32.OpenFileDialog();
            if (true == openFileDialog.ShowDialog())
            {
                textFileName.Text = openFileDialog.FileName;
                System.IO.FileInfo fileInfo = new System.IO.FileInfo(openFileDialog.FileName);
                textExt.Text = fileInfo.Extension;
            }

            //System.Windows.Forms.OpenFileDialog openFileDialog
            //= new System.Windows.Forms.OpenFileDialog();

            //if (System.Windows.Forms.DialogResult.OK == openFileDialog.ShowDialog())
            //{

            //    textFileName.Text = openFileDialog.FileName;
            //    System.IO.FileInfo fileInfo = new System.IO.FileInfo(openFileDialog.FileName);
            //    textExt.Text = fileInfo.Extension;
            //}
           


        }
    }
}
