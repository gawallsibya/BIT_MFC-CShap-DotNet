using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Page02 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (PreviousPage != null)
        {
            Control Mas = Page.PreviousPage.Master.FindControl("MainContent");
            Label Temp = (Label)Mas.FindControl("Label_text");
            Label1.Text = Temp.Text;
        }
    }
    
}