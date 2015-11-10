using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows.Media.Imaging;
using System.Collections.Specialized;
using System.Windows.Controls;


namespace PhotoCooperative
{
    public class ImageFile
    {


        public String Path { get; set; }
        public Uri TheUri { get; set; }
        public BitmapFrame Image { get; set; }


        public ImageFile(string path)
        {
            Path = path;
            TheUri = new Uri(Path);
            Image = BitmapFrame.Create(TheUri);
        }

        public override string ToString()
        {
            return Path;
        }

    }

    public class PhotoList : ObservableCollection<ImageFile>
    {
        DirectoryInfo theDirectoryInfo;

        public PhotoList() { }

        public PhotoList(string path) : this(new DirectoryInfo(path)) { }

        public PhotoList(DirectoryInfo directory)
        {
            theDirectoryInfo = directory;
            Update();
        }

        public string Path
        {
            set
            {
                theDirectoryInfo = new DirectoryInfo(value);
                Update();
            }
            get { return theDirectoryInfo.FullName; }
        }

        public DirectoryInfo Directory
        {
            set
            {
                theDirectoryInfo = value;
                Update();
            }
            get { return theDirectoryInfo; }
        }
        private void Update()
        {
            foreach (FileInfo f in theDirectoryInfo.GetFiles("*.gif"))
            {
                Add(new ImageFile(f.FullName));
            }
        }


    }

    public class PrintType
    {
        public String Description { get; set; }
        public double Price { get; set; }


        public PrintType(string description, double price)
        {
            Description = description;
            Price = price;
        }

        public override string ToString()
        {
            return Description;
        }


    }

    public class PrintTypeList : ObservableCollection<PrintType>
    {
        public PrintTypeList()
        {
            Add(new PrintType("5x7 Print", 0.49));
            Add(new PrintType("Holiday Card", 1.99));
            Add(new PrintType("Sweatshirt", 19.99));
        }
    }

    public class PrintBase : INotifyPropertyChanged
    {
        private BitmapSource aPhoto;
        private PrintType aPrintType;
        private int aQuantity;

        public PrintBase(BitmapSource photo, PrintType printtype, int quantity)
        {
            Photo = photo;
            PrintType = printtype;
            Quantity = quantity;
        }

        public PrintBase(BitmapSource photo, string description, double cost)
        {
            Photo = photo;
            PrintType = new PrintType(description, cost);
            Quantity = 0;
        }


        public BitmapSource Photo
        {
            set { aPhoto = value; OnPropertyChanged("Photo"); }
            get { return aPhoto; }
        }


        public PrintType PrintType
        {
            set { aPrintType = value; OnPropertyChanged("PrintType"); }
            get { return aPrintType; }
        }


        public int Quantity
        {
            set { aQuantity = value; OnPropertyChanged("Quantity"); }
            get { return aQuantity; }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(String info)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(info));
        }

        public override string ToString()
        {
            return PrintType.ToString();
        }
    }

    public class Print : PrintBase
    {
        public Print(BitmapSource photo) : base(photo, "5x7 Print", 0.49) { }
    }

    public class GreetingCard : PrintBase
    {
        public GreetingCard(BitmapSource photo) : base(photo, "Greeting Card", 1.99) { }
    }

    public class SShirt : PrintBase
    {
        public SShirt(BitmapSource photo) : base(photo, "Sweatshirt", 19.99) { }
    }

    public class PrintList : ObservableCollection<PrintBase> { }

}
