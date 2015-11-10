using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;

namespace CheckOut
{
    public class ShoppingCart : List<ShoppingCartItem>
    {
    }


    public class ShoppingCartItem
    {
       
        public ShoppingCartItem()
        {
            this.Item = string.Empty;
            this.Value = string.Empty;
            this.ShortDescription = string.Empty;
            this.SKU = -1;
            this.LongDescription = string.Empty;
        }
 
        public string Item
        {
            get;
            set;
        }
        public string Value
        {
            get;
            set;
        }
        public string ShortDescription
        {
            get;
            set;
        }
        public int SKU
        {
            get;
            set;
        }
        public string LongDescription
        {
            get;
            set;
        }
    }

}
