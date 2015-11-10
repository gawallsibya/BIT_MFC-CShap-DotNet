using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.Animation;
using System.Windows.Input;
using System.Collections;


namespace PhotoCooperative
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>

    public partial class Window1 : System.Windows.Window
    {

        public Window1()
        {
            InitializeComponent();
            UndoStack = new Stack();
        }

        private void WindowLoaded(object sender, EventArgs e)
        {
            AdornerLayer layer = AdornerLayer.GetAdornerLayer(CurrentPhoto);
            CropSelector = new RubberbandAdorner(CurrentPhoto);
            CropSelector.Window = this;
            layer.Add(CropSelector);
            CropSelector.Rubberband.Visibility = Visibility.Hidden;

        }

        public PhotoList Photos;
        public PrintList ShoppingCart;
        private Stack UndoStack;
        private RubberbandAdorner CropSelector;

        private void PhotoListSelection(object sender, RoutedEventArgs e)
        {
            String path = ((sender as ListBox).SelectedItem.ToString());
            BitmapSource img = BitmapFrame.Create(new Uri(path));
            CurrentPhoto.Source = img;
            ClearUndoStack();
            if (CropSelector != null)
            {

                if (Visibility.Visible == CropSelector.Rubberband.Visibility)
                    CropSelector.Rubberband.Visibility = Visibility.Hidden;


            }
            CropButton.IsEnabled = false;
        }

        private void AddToShoppingCart(object sender, RoutedEventArgs e)
        {
            if (PrintTypeComboBox.SelectedItem != null)
            {
                PrintBase item;
                switch (PrintTypeComboBox.SelectedIndex)
                {
                    case 0:
                        item = new Print(CurrentPhoto.Source as BitmapSource); break;
                    case 1:
                        item = new GreetingCard(CurrentPhoto.Source as BitmapSource); break;
                    case 2:
                        item = new SShirt(CurrentPhoto.Source as BitmapSource); break;
                    default:
                        return;
                }
                ShoppingCart.Add(item);
                ShoppingCartListBox.ScrollIntoView(item);
                ShoppingCartListBox.SelectedItem = item;
                if (false == CheckoutButton.IsEnabled)
                    CheckoutButton.IsEnabled = true;
                if (false == RemoveButton.IsEnabled)
                    RemoveButton.IsEnabled = true;
            }
        }

        private void RemoveShoppingCartItem(object sender, RoutedEventArgs e)
        {
            if (null != ShoppingCartListBox.SelectedItem)
            {
                PrintBase item = ShoppingCartListBox.SelectedItem as PrintBase;
                ShoppingCart.Remove(item);
                ShoppingCartListBox.SelectedIndex = ShoppingCart.Count - 1;
            }
            if (ShoppingCart.Count == 0)
            {
                RemoveButton.IsEnabled = false;
                CheckoutButton.IsEnabled = false;
            }
        }

        private void Checkout(object sender, RoutedEventArgs e)
        {
            if (ShoppingCart.Count > 0)
            {
                Checkout co = new Checkout();
                co.ShoppingCart = ShoppingCart;
                co.Show();
                this.Hide();
            }
        }

        private void OnMouseDown(object sender, MouseButtonEventArgs e)
        {
            Point anchor = e.GetPosition(CurrentPhoto);
            CropSelector.CaptureMouse();
            CropSelector.StartSelection(anchor);
            CropButton.IsEnabled = true;
        }

        private void Crop(object sender, RoutedEventArgs e)
        {
            if (CurrentPhoto.Source != null)
            {
                BitmapSource img = (BitmapSource)(CurrentPhoto.Source);
                UndoStack.Push(img);
                Int32Rect rect = new Int32Rect();
                rect.X = (int)(CropSelector.SelectRect.X * img.PixelWidth / CurrentPhoto.ActualWidth);
                rect.Y = (int)(CropSelector.SelectRect.Y * img.PixelHeight / CurrentPhoto.ActualHeight);
                rect.Width = (int)(CropSelector.SelectRect.Width * img.PixelWidth / CurrentPhoto.ActualWidth);
                rect.Height = (int)(CropSelector.SelectRect.Height * img.PixelHeight / CurrentPhoto.ActualHeight);
                CurrentPhoto.Source = new CroppedBitmap(img, rect);

                CropSelector.Rubberband.Visibility = Visibility.Hidden;
                CropButton.IsEnabled = false;
                UndoButton.IsEnabled = true;
            }
        }

        private void Undo(object sender, RoutedEventArgs e)
        {
            if (UndoStack.Count > 0)
            {
                CurrentPhoto.Source = (BitmapSource)UndoStack.Pop();
            }
            if (UndoStack.Count == 0)
            {
                UndoButton.IsEnabled = false;
            }
        }

        private void ClearUndoStack()
        {
            UndoStack.Clear();
            UndoButton.IsEnabled = false;
        }

    }
}