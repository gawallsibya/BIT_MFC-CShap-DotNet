using System;
using System.Collections;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;











public partial class LastNameLookup : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        if (Request.QueryString.Count > 0)
        {
            String queryLastName =
               Request.QueryString.Get(0).ToString();
            DataTable dt = LastNamesForPartialName(queryLastName);

            if (dt == null || dt.Rows.Count == 0)
            {
                LastNames.Text =
                   "Sorry no one found with that letter combination";
            }
            else
            {
                String returnString = "<select size=10 >";
                foreach (DataRow row in dt.Rows)
                {
                    returnString += "<option>" +
                        row["lastName"].ToString() +
                        "</option>";
                }
                returnString += "</select>";
                LastNames.Text = returnString;
            }
        }
        else
        {
            LastNames.Text = string.Empty;
        }
    }

    public DataTable LastNamesForPartialName(String aPartialName)
    {
        String connectionString = ConfigurationManager.AppSettings["Database"];
        SqlConnection connection = new SqlConnection(connectionString);

        string queryString = "select * from LastNames where lastName like '" +
                               aPartialName + "%'";
        DataSet ds = new DataSet();

        try
        {
            SqlDataAdapter dataAdapter =
                  new SqlDataAdapter(queryString, connection);
            dataAdapter.Fill(ds, "LastNames");
        }

        catch
        {
            // Handle exception
        }

        finally
        {
            connection.Close();
        }
        return ds.Tables["LastNames"];
    }
}

