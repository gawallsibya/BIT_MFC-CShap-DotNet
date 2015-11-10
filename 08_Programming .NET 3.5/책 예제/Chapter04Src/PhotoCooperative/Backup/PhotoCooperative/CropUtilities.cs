using System;
using System.IO;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Documents;

namespace PhotoCooperative
{
    public class RubberbandAdorner : Adorner
    {
        public Window1 Window { set; get; }
        private RectangleGeometry geometry;
        public System.Windows.Shapes.Path Rubberband { get; set; }
        private UIElement adornedElement;
        private Rect selectRect;
        public Rect SelectRect { get { return selectRect; } }
        protected override int VisualChildrenCount { get { return 1; } }
        private Point anchorPoint;

        public RubberbandAdorner(UIElement adornedElement)
            : base(adornedElement)
        {
            this.adornedElement = adornedElement;
            selectRect = new Rect();

            Rubberband = new System.Windows.Shapes.Path();

            geometry = new RectangleGeometry();

            Rubberband.Data = geometry;
            Rubberband.StrokeThickness = 2;
            Rubberband.Stroke = Brushes.Yellow;
            Rubberband.Opacity = .6;
            Rubberband.Visibility = Visibility.Hidden;

            AddVisualChild(Rubberband);
            MouseMove += new MouseEventHandler(DrawSelection);
            MouseUp += new MouseButtonEventHandler(EndSelection);
        }

        protected override Size ArrangeOverride(Size size)
        {
            Size finalSize = base.ArrangeOverride(size);
            ((UIElement)GetVisualChild(0)).Arrange(new Rect(new Point(), finalSize));
            return finalSize;
        }

        public void StartSelection(Point anchorPoint)
        {
            this.anchorPoint = anchorPoint;
            selectRect.Size = new Size(10, 10);
            selectRect.Location = anchorPoint;
            geometry.Rect = selectRect;
            if (Visibility.Visible != Rubberband.Visibility)
                Rubberband.Visibility = Visibility.Visible;
        }

        private void DrawSelection(object sender, MouseEventArgs e)
        {
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                Point mousePosition = e.GetPosition(adornedElement);
                if (mousePosition.X < anchorPoint.X)
                {
                    selectRect.X = mousePosition.X;
                }
                else
                {
                    selectRect.X = anchorPoint.X;
                }
                if (mousePosition.Y < anchorPoint.Y)
                {
                    selectRect.Y = mousePosition.Y;
                }
                else
                {
                    selectRect.Y = anchorPoint.Y;
                }
                selectRect.Width = Math.Abs(mousePosition.X - anchorPoint.X);
                selectRect.Height = Math.Abs(mousePosition.Y - anchorPoint.Y);
                geometry.Rect = selectRect;
                AdornerLayer layer = AdornerLayer.GetAdornerLayer(adornedElement);
                layer.InvalidateArrange();
            }
        }

        private void EndSelection(object sender, MouseButtonEventArgs e)
        {
            const int MinSize = 3;

            if (selectRect.Width <= MinSize || selectRect.Height <= MinSize)
            {
                Rubberband.Visibility = Visibility.Hidden;
            }
            else
            {
                Window.CropButton.IsEnabled = true;
            }
            ReleaseMouseCapture();
        }

        protected override Visual GetVisualChild(int index)
        {
            return Rubberband;
        }
    }
}
