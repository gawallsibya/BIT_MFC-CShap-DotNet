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

namespace SimpleGrid
{
    public partial class Page : UserControl
    {
        public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender, RoutedEventArgs e)
        {
            myPushyButton.Click +=new RoutedEventHandler(myPushyButton_Click);

        }

        private void myPushyButton_Click(object sender, RoutedEventArgs e)
        {
            myPushyButton.Width *= 1.25;
            myPushyButton.Content = "Thanks, I needed that!";
        }


    }
}
