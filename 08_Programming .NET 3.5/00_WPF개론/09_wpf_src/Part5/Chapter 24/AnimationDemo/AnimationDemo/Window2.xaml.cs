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
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
        }

        private void btnmyanimationStart_Click(object sender, RoutedEventArgs e)
        {
            DoubleAnimationUsingKeyFrames animation = (FindResource("myAnimation") as DoubleAnimationUsingKeyFrames);
            myEllipse.BeginAnimation(LeftProperty, animation);
            
        }
    }
}
