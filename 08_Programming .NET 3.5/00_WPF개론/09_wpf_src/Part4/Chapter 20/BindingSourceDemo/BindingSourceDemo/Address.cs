using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;

namespace BindingSourceDemo
{
    public class Address : INotifyPropertyChanged
    {
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

        private string currentAddress;

        public string CurrentAddress
        {
            get { return currentAddress; }
            set { 
                    currentAddress = value;
                    OnPropertyChanged("CurrentAddress");
            }
        }
        private string birthAddress;

        public string BirthAddress
        {
            get { return birthAddress; }
            set { 
                    birthAddress = value;
                    OnPropertyChanged("BirthAddress");
                }
        }
    }
}
