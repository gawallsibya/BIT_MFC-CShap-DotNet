using System;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.BindingHelpers;
using MvcApplication.Models;

namespace MvcApplication.Controllers
{
    public class PersonController : Controller
    {
        MVCDatabaseDataContext db = new MVCDatabaseDataContext();

        [ControllerAction]
        public void PeopleList()
        {
            PersonViewData pvd = new PersonViewData();
            pvd.People = db.GetPeople();
            RenderView("PeopleLister", pvd);
        }


        // Person/New

        [ControllerAction]
        public void New()
        {
            NewPersonViewData npvd = new NewPersonViewData();
            npvd.Shippers = db.GetShippers();
            RenderView("New", npvd);
        }

        // Person/NewInsert

        [ControllerAction]
        public void NewInsert()
        {
            Person p = new Person();
            p.UpdateFrom(Request.Form);

            db.AddPerson(p);
            db.SubmitChanges();

            RedirectToAction(new { Controller = "Person", Action = "PeopleList" });
        }

    }
}
