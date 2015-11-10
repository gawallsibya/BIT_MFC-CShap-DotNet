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

namespace WPFControls
{
    /// <summary>
    /// DockPanelSample.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class DockPanelSample : Window
    {
        public DockPanelSample()
        {
            InitializeComponent();
        }

        private void Grid_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DockPanel.SetDock(e.Source as Grid, Dock.Top);
            MessageBox.Show("a");
        }

       
    }
}
