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
using System.ComponentModel;

namespace LayoutDemo
{
    public class DemoPanel : Panel
    {

        protected override Size MeasureOverride(Size availableSize)
        {
            double totalWidth = 0;
            double totalHeight = 0;

            foreach (UIElement child in Children)
            {
                child.Measure(new Size(double.PositiveInfinity,double.PositiveInfinity));
                //child.Measure(new Size(70,70));
                Size childSize = child.DesiredSize;
                totalWidth += childSize.Width;
                totalHeight += childSize.Height;
            }

            return new Size(totalWidth, totalHeight);
        }

        protected override Size ArrangeOverride(Size finalSize)
        {
            Point currentPosition = new Point();

            foreach (UIElement child in Children)
            {
                Rect childRect = new Rect(currentPosition, child.DesiredSize);
                //Rect childRect = new Rect(currentPosition, new Size(100,100));
                child.Arrange(childRect);
                currentPosition.Offset(childRect.Width, childRect.Height);
                
            }

            return new Size(currentPosition.X, currentPosition.Y);
        }
    }




    public class SamplePanel : Panel
    {

        protected override Size MeasureOverride(Size availableSize)
        {
            double totalWidth = 0;
            double totalHeight = 0;

            foreach (UIElement child in Children)
            {
                child.Measure(new Size(double.PositiveInfinity, double.PositiveInfinity));
                Size childSize = child.DesiredSize;
                totalWidth += childSize.Width;
                totalHeight += childSize.Height;
            }

            return new Size(totalWidth, totalHeight);
        }

        protected override Size ArrangeOverride(Size finalSize)
        {
            double x = 0;
            double y = 0;
            
            foreach (UIElement child in Children)
            {

                child.Arrange(new Rect(new Point(x, y), child.DesiredSize));
                x += child.DesiredSize.Width;
                y += child.DesiredSize.Height;

            }

            return finalSize;
        }
    }

     
}
 



