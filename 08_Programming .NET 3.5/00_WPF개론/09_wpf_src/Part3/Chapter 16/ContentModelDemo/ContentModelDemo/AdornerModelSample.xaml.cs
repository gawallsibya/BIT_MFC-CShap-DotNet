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

namespace ContentModelDemo
{
    /// <summary>
    /// AdornerModelSample.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class AdornerModelSample : Window
    {
        AdornerLayer al;

        public AdornerModelSample()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            al = AdornerLayer.GetAdornerLayer(myRectangle);
            al.Add(new MyAdorner(myRectangle));
        }
    }

    public class MyAdorner : Adorner
    {
        public MyAdorner(UIElement adornedElement) : base(adornedElement) { }
        protected override void OnRender(DrawingContext drawingContext)
        {

            Rect adornedElementRect = new Rect(this.AdornedElement.DesiredSize);

            SolidColorBrush renderBrush = new SolidColorBrush(Colors.Green);
            renderBrush.Opacity = 0.2;
            Pen renderPen = new Pen(new SolidColorBrush(Colors.Navy), 1.5);
            double renderRadius = 5.0;

            drawingContext.DrawEllipse(renderBrush, renderPen,
                     adornedElementRect.TopLeft, renderRadius, renderRadius);
            drawingContext.DrawText(MakeFormattedString(
                     adornedElementRect.TopLeft), adornedElementRect.TopLeft);
            // 중략 위와 사각형 네 귀에 위와 동일한 코드 
        }

        private FormattedText MakeFormattedString(Point point)
        {
            string testString = point.ToString();
            FormattedText formattedText = new FormattedText(testString,
            System.Globalization.CultureInfo.GetCultureInfo("ko-kr"),
            FlowDirection.LeftToRight,
            new Typeface("Verdana"), 16, Brushes.Black);

            return formattedText;
        }
    }

}
