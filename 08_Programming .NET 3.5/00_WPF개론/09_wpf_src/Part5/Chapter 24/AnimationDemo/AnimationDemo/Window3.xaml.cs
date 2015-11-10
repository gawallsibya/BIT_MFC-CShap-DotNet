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
using System.Windows.Media.Animation;

namespace AnimationDemo
{
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        private void btnStartAnimation_Click(object sender, RoutedEventArgs e)
        {
            DoubleAnimationUsingPath animationX = FindResource("animationX") as DoubleAnimationUsingPath;
            ellipse1.BeginAnimation(Canvas.LeftProperty, animationX);

            DoubleAnimationUsingPath animationY = FindResource("animationY") as DoubleAnimationUsingPath;
            ellipse1.BeginAnimation(Canvas.TopProperty, animationY);

        }

        
    }
}
