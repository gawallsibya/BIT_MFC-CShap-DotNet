using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

namespace BookDisplay
{
    public partial class Page : UserControl
    {
         public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender,
            RoutedEventArgs e)
        {
                        
            Book book = new Book();
            InitializeProgramming(book);
            LayoutRoot.DataContext = book;
        }

        private void InitializeProgramming(Book b)
        {
            b.Title = "Programming Silverlight";
            b.Author = "Jesse Liberty, Tim Heuer";
            b.MultipleAuthor = true;
            b.QuantityOnHand = 20;
            b.Chapters = new List<string>() { "Introduction", "Controls", "Events", "Data", "Styles and Templates",
                    "Media", "Graphics", "Text", "Animation", "Custom Controls", "Network", "Web Services", "App Model"};
        }


    }
}
