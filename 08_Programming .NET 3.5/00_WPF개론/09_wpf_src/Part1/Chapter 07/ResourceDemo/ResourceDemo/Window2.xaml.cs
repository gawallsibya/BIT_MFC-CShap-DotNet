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

namespace ResourceDemo
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

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            SolidColorBrush brush=
            grid.Resources["BrushGreen"] as SolidColorBrush;
            rectangle1.Fill = brush;
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            SolidColorBrush brush =
                new SolidColorBrush(Colors.Yellow);
            grid.Resources.Add("BrushYellow", brush);

        }
    }
}
