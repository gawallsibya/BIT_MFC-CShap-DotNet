using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace DynamicControls
{
    public partial class Page : UserControl
    {
        private enum Platform { Web, Desktop } ;
        private StackPanel dynamicStackPanel = null;
        public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender, RoutedEventArgs e)
        {
            Web.Checked += new RoutedEventHandler(Web_Checked);
            Desk.Checked += new RoutedEventHandler(Desk_Checked);
        }

        void Desk_Checked(object sender, RoutedEventArgs e)
        {
            SetChoices(Platform.Desktop);
        }

        void Web_Checked(object sender, RoutedEventArgs e)
        {
            SetChoices(Platform.Web);
        }

        private void SetChoices(Platform platform)
        {
            if ( dynamicStackPanel != null )
                dynamicStackPanel.Children.Clear();
            dynamicStackPanel = new StackPanel();
            dynamicStackPanel.Orientation = Orientation.Horizontal;
            dynamicStackPanel.SetValue(Grid.RowProperty, 1);
            dynamicStackPanel.SetValue(Grid.ColumnProperty, 3);
            if (platform == Platform.Desktop)
            {
                CheckBox cb = new CheckBox();
                cb.Content = "Winforms";
                cb.Height = 30;
                cb.Width = 90;
                dynamicStackPanel.Children.Add(cb);
                cb = new CheckBox();
                cb.Content = "WPF";
                cb.Height = 30;
                cb.Width = 50;
                dynamicStackPanel.Children.Add(cb);
            }
            else
            {
                CheckBox cb = new CheckBox();
                cb.Content = "AJAX";
                cb.Height = 30;
                cb.Width = 60;
                dynamicStackPanel.Children.Add(cb);
                cb = new CheckBox();
                cb.Content = "Silverlight";
                cb.Height = 30;
                cb.Width = 90;
                dynamicStackPanel.Children.Add(cb);
            }
            LayoutRoot.Children.Add(dynamicStackPanel);
        }


    }
}
