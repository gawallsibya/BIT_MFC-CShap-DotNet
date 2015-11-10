using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class MasterPage : System.Web.UI.MasterPage
{
    string str;
    public string Str
    {
        set { str = value; }
        get { return str; }
    }
    protected void Page_Load(object sender, EventArgs e)
    {

    }
}
