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

namespace RoutedEvents
{
    public partial class Page : UserControl
    {
        private int counterOne = 0;
        private int counterTwo = 0;
        private int counterThree = 0;
        private Brush ButtonTwoDefaultBG;
        private Brush ButtonTwoDefaultFG;
        public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender, RoutedEventArgs e)
        {
            ButtonOne.Click +=new RoutedEventHandler(ButtonOne_Click);
            ButtonTwo.MouseLeftButtonDown += new MouseButtonEventHandler(ButtonTwo_MouseLeftButtonDown);
            ButtonTwo.MouseLeftButtonUp += new MouseButtonEventHandler(ButtonTwo_MouseLeftButtonUp);
            Quiet.Click += new RoutedEventHandler(Mood_Click);
            Active.Click +=new RoutedEventHandler(Mood_Click);
            Noisy.Click += new RoutedEventHandler(Mood_Click);
            Frenetic.Click += new RoutedEventHandler(Mood_Click);
            SetFeatures.MouseLeftButtonUp += new MouseButtonEventHandler(SetFeatures_MouseLeftButtonUp);
            theSlider.ValueChanged += new RoutedPropertyChangedEventHandler<double>(theSlider_ValueChanged);

        }

        void theSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            SliderEffect.Text = theSlider.Value.ToString("N");
        }

        void SetFeatures_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            FeaturesEffects.Text = "Button Clicked " + (++counterTwo).ToString();
        }



        void Mood_Click(object sender, RoutedEventArgs e)
        {
            RadioButton rb = e.Source as RadioButton;
            MoodEffect.Text = rb.Content.ToString();
        }

        void ButtonTwo_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ButtonTwo.Background = ButtonTwoDefaultBG;
            ButtonTwo.Foreground = ButtonTwoDefaultFG;
            ButtonOneResponse.Text = "Button Two Pressed " + (++counterTwo).ToString();
            
        }

        void ButtonTwo_MouseLeftButtonDown(
            object sender, MouseButtonEventArgs e)
        {
            ButtonTwoDefaultBG = ButtonTwo.Background;
            ButtonTwoDefaultFG = ButtonTwo.Foreground;
            ButtonTwo.Background = new SolidColorBrush(Colors.Black);
            ButtonTwo.Foreground = new SolidColorBrush(Colors.White);
        }

        private void ButtonOne_Click(
            object sender, RoutedEventArgs e)
        {
            ButtonOneResponse.Text = "Button One Pressed " + (++counterOne).ToString();
        }
    }
}
