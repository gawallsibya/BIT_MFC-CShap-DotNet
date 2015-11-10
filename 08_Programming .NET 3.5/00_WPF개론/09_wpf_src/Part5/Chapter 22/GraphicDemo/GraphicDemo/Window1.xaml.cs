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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GraphicDemo
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void Rectangle_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Point pt= e.GetPosition(sender as IInputElement);
            Point spt = (sender as Visual).PointToScreen(pt);
        }

        private void Rectangle_MouseDown_1(object sender, MouseButtonEventArgs e)
        {
            this.Top = 0; this.Left = 10;
        }
    }
}
