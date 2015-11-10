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
using System.Xml;

namespace DataBindingBasicDemo
{
    /// <summary>
    /// Window6.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window6 : Window
    {
        
        public Window6()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window6_Loaded);
        }

        void Window6_Loaded(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void btnMoveNext_Click(object sender, RoutedEventArgs e)
        {
            genreListBox.Items.MoveCurrentToNext();
        }

        private void btnMovePrevious_Click(object sender, RoutedEventArgs e)
        {
            genreListBox.Items.MoveCurrentToPrevious();
        }

        private void btnfilter_Click(object sender, RoutedEventArgs e)
        {
            genreListBox.Items.Filter = new Predicate<object>(SelectItem);
        }
        private bool SelectItem(object sender)
        {
            XmlElement xe = sender as XmlElement;
            if (xe.Attributes["name"].Value == "Poem")
                return true;
            else
                return false;
        }

        private void btnUnfilter_Click(object sender, RoutedEventArgs e)
        {
            genreListBox.Items.Filter = null;
        }
    }
}
