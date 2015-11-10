using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CheckOut
{
    public class ShoppingCartItem
    {
        public ShoppingCartItem()
        {
            this.Item = string.Empty;
            this.Value = string.Empty;
            this.ShortDescription = string.Empty;
            this.SKU = -1;
        }
 
        public ShoppingCartItem(
            string item,
            string value,
            string shortDescription,
            int sku)
        {
            this.Item = item;
            this.Value = value;
            this.ShortDescription = shortDescription;
            this.SKU = sku;
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
    }

}
