using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;

namespace DataTemplateDemo
{
    public class Person : INotifyPropertyChanged
    {

        public Person()
        {

        }

       

        #region INotifyPropertyChanged 멤버

        public event PropertyChangedEventHandler PropertyChanged;



        protected void OnPropertyChanged(string name)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(name));
            }
        }

        #endregion
        private string irum;
        public string Irum
        {
            get
            {
                return irum;
            }
            set
            {
                irum = value;
                OnPropertyChanged("Irum");
            }
        }

        private string juso;
        public string Juso
        {
            get
            {
                return juso;
            }
            set
            {
                juso = value;
                OnPropertyChanged("Juso");
            }
        }

        private string hobby;
        public string  Hobby
        {
            get
            {
                return hobby;
            }
            set
            {
                hobby = value;
                OnPropertyChanged("Hobby");
            }
        }
        

    }
}
