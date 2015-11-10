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
using System.ComponentModel;
namespace DataBindingBasicDemo
{
    class Person : INotifyPropertyChanged
    {
       

        string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                NotifyPropertyChanged("Name");
            }
        }
        string juso;
        public string Juso
        {
            get { return juso; }
            set
            {
                juso = value;
                NotifyPropertyChanged("Juso");
            }
        }

        #region INotifyPropertyChanged 멤버

        public event PropertyChangedEventHandler PropertyChanged;
        private void NotifyPropertyChanged(String info)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(info));
            }
        }


        #endregion
    }
}
