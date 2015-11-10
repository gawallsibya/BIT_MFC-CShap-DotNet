using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace BindingSourceDemo
{
    class MyDataSource
    {
        string fast = "fast";
        public string Fast
        {
            get { return fast; }
            set { fast = value; }
        }
        string slow = "slow";
        public string Slow
        {
            get
            {
                Thread.Sleep(4000);
                return slow;
            }
            set { slow = value; }
        }
        string midterm = "midterm";
        public string Midterm
        {
            get
            {
                Thread.Sleep(2000);
                return midterm;
            }
            set { midterm = value; }
        }
    }

}
