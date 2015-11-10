using System;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.Xml.Linq;


    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class Service : System.Web.Services.WebService
    {
        public Service()
        {

            //Uncomment the following line if using designed components 
            //InitializeComponent(); 
        }

        [WebMethod(EnableSession = true)]
        public string WelcomeInstructions()
        {
            bool orderNumberNotNull = (Session["orderNumber"] != null);

            if (orderNumberNotNull)
            {
                throw new InvalidOperationException();
            }
            else
            {
                String orderNumber = "W123456";
                Session["orderNumber"] = orderNumber;
                return "Please enter your order number: " + orderNumber + "\n\n";
            }

        }

        [WebMethod(EnableSession = true)]
        public string GetOrderStatusForOrderNumber(String s)
        {
            bool orderNumberIsNull = (Session["orderNumber"] == null);
            bool retrievedStatus = (Session["retrievedStatus"] != null);

            if (orderNumberIsNull)
            {
                throw new InvalidOperationException();
            }
            else
            {
                if (retrievedStatus)
                {
                    throw new InvalidOperationException();
                }
                else
                {
                    if (Session["orderNumber"].Equals(s))
                    {
                        Session["retrievedStatus"] = true;
                        return "Your order is being prepared for shipment";
                    }
                    else
                    {
                        Session["retrievedStatus"] = true;
                        return "Invalid order number...";
                    }
                }
            }


        }

    }