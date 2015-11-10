using System;
using System.Collections.Generic;
using MvcApplication.Models;

namespace MvcApplication.Models
{
    public class PersonViewData
    {
        public List<Person> People { get; set; }
    }
    public class NewPersonViewData
    {
        public List<ShippingMethod> Shippers { get; set; }
    }
}

