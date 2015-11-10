using System;
using System.Collections.Generic;
using System.Text;

namespace StyleDemo
{
    public class Animal
    {
        public Animal() { }
        public Animal(string irum,string juso)
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
        string gender;

        public string Gender
        {
            get { return gender; }
            set { gender = value; }
        }
        
    }

    public class Animals : List<Animal>
    {

        public Animals()
        { 
            Add(new Animal("Tiger","Asia"));
            Add(new Animal("Lion", "Africa"));
            Add(new Animal("Cat", "Room"));
            Add(new Animal("Dog", "Anywhere"));             
        }
    }
}
