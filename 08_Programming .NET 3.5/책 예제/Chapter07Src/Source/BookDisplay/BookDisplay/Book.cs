using System.ComponentModel;
using System.Collections;
using System.Collections.Generic;

namespace BookDisplay
{
    public class Book : INotifyPropertyChanged
    {
        private string bookTitle;
        private string bookAuthor;
        private int quantityOnHand;
        private bool multipleAuthor;
        private string authorURL;
        private string authorWebPage;
        private List<string> myChapters;


        // implement the required event for the interface
        public event PropertyChangedEventHandler PropertyChanged;

        public string Title
        {
            get { return bookTitle; }
            set
            {
                bookTitle = value;
                NotifyPropertyChanged("Title");
            }       // end set
        }           // end property

        public string Author
        {
            get { return bookAuthor; }
            set
            {
                bookAuthor = value;
                NotifyPropertyChanged("Author");
            }       // end set

        }

        public List<string> Chapters
        {
            get { return myChapters; }
            set
            {
                myChapters = value;
                NotifyPropertyChanged("Chapters");
            }
        }


        public bool MultipleAuthor
        {
            get { return multipleAuthor; }
            set
            {
                multipleAuthor = value;
                NotifyPropertyChanged("MultipleAuthor");
            }       // end set
        }



        public int QuantityOnHand
        {
            get { return quantityOnHand; }
            set
            {
                quantityOnHand = value;
                NotifyPropertyChanged("QuantityOnHand");
            }       // end set
        }


        // factoring out the call to the event
        public void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this,
                    new PropertyChangedEventArgs(propertyName));
            }

        }
    }               // end class
}
