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

namespace RoundButton
{
    public partial class Page : UserControl
    {
        public Page()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Page_Loaded);
        }

        void Page_Loaded(object sender, RoutedEventArgs e)
        {
            Book book = new Book();
            InitializeProgramming(book);
            LayoutRoot.DataContext = book;
            Title.Click += new RoutedEventHandler(Title_Click);
            Author.Click += new RoutedEventHandler(Author_Click);
            Chapters.MouseLeftButtonUp += new MouseButtonEventHandler(
                  Chapters_MouseLeftButtonUp);
        }

        void Chapters_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ChapterOutput.Text = ChapterLB.SelectedItem.ToString();
        }


        void Author_Click(object sender, RoutedEventArgs e)
        {
            AuthorOutput.Text = Author.Content.ToString();
        }

        void Title_Click(object sender, RoutedEventArgs e)
        {
            TitleOutput.Text = Title.Content.ToString();
        }

        private void InitializeProgramming(Book b)
        {
            b.Title = "Programming Silverlight";
            b.Author = "Jesse Liberty, Tim Heuer";
            b.MultipleAuthor = true;
            b.QuantityOnHand = 20;
            b.Chapters = new List<string>() 
           { 
           "Introduction", "Controls", 
           "Events", "Data", "Styles and Templates",
            "Media", "Graphics", "Text", "Animation", "Custom Controls", 
            "Network", "Web Services", "App Model"
           };
        }
    }
}
