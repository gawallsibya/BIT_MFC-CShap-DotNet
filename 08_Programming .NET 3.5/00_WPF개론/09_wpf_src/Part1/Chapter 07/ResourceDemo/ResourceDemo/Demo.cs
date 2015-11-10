using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Collections.ObjectModel;
using System.ComponentModel;


namespace ResourceDemo
{
    public class Animal
    {
        public Animal() { }
        public Animal(string irum, string juso)
        {
            this.irum = irum;
            this.juso = juso;
        }
        string irum;

        public string Irum
        {
            get { return irum; }
            set { irum = value; }
        }
        string juso;

        public string Juso
        {
            get { return juso; }
            set { juso = value; }
        }
    }


    public class Greeting
    { 
    
        public string SayHello(string irum)
        {
            return "Hello  " + irum;
        }
    
    }

    

}
