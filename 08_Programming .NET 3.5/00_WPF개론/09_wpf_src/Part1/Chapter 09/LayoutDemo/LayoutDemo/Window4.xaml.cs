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

namespace LayoutDemo
{
    /// <summary>
    /// Window4.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window4 : Window
    {
        public Window4()
        {
            InitializeComponent();
        }

        private void Canvas_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            SwapZIndex(ellipseCanvas, rectangleCanvas);
                     
        }
        private void SwapZIndex(Panel panel1, Panel panel2)
        {
            int tempZIndex = Panel.GetZIndex(panel1);
            Panel.SetZIndex(panel1, Panel.GetZIndex(panel2));
            Panel.SetZIndex(panel2, tempZIndex);
        }

    }
}
