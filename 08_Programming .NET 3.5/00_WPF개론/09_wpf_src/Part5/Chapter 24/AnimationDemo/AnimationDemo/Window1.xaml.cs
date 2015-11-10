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
using System.Windows.Media.Animation;

namespace AnimationDemo
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

        private void btnAnimationStart_Click(object sender, RoutedEventArgs e)
        {
            DoubleAnimation animation=new DoubleAnimation(400,new Duration(TimeSpan.FromSeconds(5)));
            animation.AutoReverse = true;
            myEllipse.BeginAnimation(LeftProperty, animation, HandoffBehavior.Compose); 
            
        }

        private void BtnColorAnimationStart_Click(object sender, RoutedEventArgs e)
        {
            ColorAnimation animation = new ColorAnimation(Colors.Blue, new Duration(TimeSpan.FromSeconds(5)));
            animation.AutoReverse = true;
            SolidColorBrush brush = (sender as FrameworkElement).FindResource("brush") as SolidColorBrush;
            brush.BeginAnimation(SolidColorBrush.ColorProperty, animation);
            
            
        }

        private void btnRadiusAnimation_Click(object sender, RoutedEventArgs e)
        {
            DoubleAnimation animation = new DoubleAnimation(200, new Duration(TimeSpan.FromSeconds(5)));
            animation.AutoReverse = true;
            myEllipse.BeginAnimation(WidthProperty, animation);
            myEllipse.BeginAnimation(HeightProperty, animation);
        }

        private void ResourceAnimation_Click(object sender, RoutedEventArgs e)
        {
            DoubleAnimation animantion
                = (sender as FrameworkElement).FindResource("myAnimation") as DoubleAnimation;
            myEllipse.BeginAnimation(LeftProperty, animantion);

        }
    }
}
