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

namespace WindowDemo
{
    /// <summary>
    /// Window6.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window6 : Window
    {
        public Window6()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            DialogWindow dialog = new DialogWindow();
            dialog.Owner = this;
            if (dialog.ShowDialog().Value)
            {
                textOk.Text = "OK";
                this.textName.Text= dialog.textName.Text;
                this.textJuso.Text  = dialog.textAddress.Text;
            }
            else
            {
                textOk.Text = "NO";
                this.textName.Text= "";
                this.textJuso.Text  = "";
            }

        }
    }
}
