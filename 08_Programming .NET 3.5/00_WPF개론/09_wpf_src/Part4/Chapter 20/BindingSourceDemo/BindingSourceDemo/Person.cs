using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.Collections.ObjectModel;

namespace BindingSourceDemo
{
    public class Person : INotifyPropertyChanged
    {

        public Person()
        { 
        
        }

        public Person(string irum,string currentAddress,string birthAddress)
        {
            this.irum = irum;
            address = new Address();
            address.BirthAddress = birthAddress;
            address.CurrentAddress = currentAddress;
        
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

        private Address address;

        public Address Address
        {
            get { return address; }
            set { 
                    address = value;
                    OnPropertyChanged("Address");
                }
        }

        private ObservableCollection<Person> friends;

        public ObservableCollection<Person> Friends
        {
            get { return friends; }
            set { friends = value; }     
            
               
        }



    }

}
