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

namespace Bubbles
{
    public partial class Page : UserControl
    {
        private int counter = 0;
        private int counterTwo = 0;
        public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender, RoutedEventArgs e)
        {
            SetFeatures.Click += new RoutedEventHandler(SetFeatures_Click);
            SetFeatures2.MouseLeftButtonUp += new MouseButtonEventHandler(SetFeatures2_MouseLeftButtonUp);
        }


        void SetFeatures_Click(object sender, RoutedEventArgs e)
        {
            FeaturesEffects.Text = "Button Clicked " + (++counter).ToString();
        }

        void SetFeatures2_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            FeaturesEffects2.Text = "Button Two Clicked " + (++counterTwo).ToString();
        }

    }
}
