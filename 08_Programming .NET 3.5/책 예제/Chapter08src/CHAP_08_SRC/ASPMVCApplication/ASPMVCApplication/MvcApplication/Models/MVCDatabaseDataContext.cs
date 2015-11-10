using System;
using System.Collections.Generic;
using System.Linq;

namespace MvcApplication.Models
{
    public partial class MVCDatabaseDataContext
    {

        // Retrieve All Person Objects

        public List<Person> GetPeople()
        {
            return Persons.ToList();
        }

        // Add a New Person

        public void AddPerson(Person p)
        {
            Persons.InsertOnSubmit(p);
        }
        // Retrieve All Shippers

        public List<ShippingMethod> GetShippers()
        {
            return ShippingMethods.ToList();
        }
    }
}
