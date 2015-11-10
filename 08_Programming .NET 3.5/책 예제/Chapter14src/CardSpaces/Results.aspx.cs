using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using Microsoft.IdentityModel.TokenProcessor;
using Microsoft.IdentityModel.Samples;
using System.IdentityModel.Claims;
using System.IdentityModel.Tokens;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

public partial class Results : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        String identityToken;
        identityToken = Request.Params["identityToken"];

        if (identityToken == null || identityToken == "")
        {
            identityToken = "Oops! Someone forgot to tell us who they were...";
        }
        else
        {
            Token aToken = new Token(identityToken);

            FirstName.Text = aToken.Claims[ClaimTypes.GivenName];
            LastName.Text = aToken.Claims[ClaimTypes.Surname];
            City.Text = aToken.Claims[ClaimTypes.Locality];
            Country.Text = aToken.Claims[ClaimTypes.Country];
            Email.Text = aToken.Claims[ClaimTypes.Email];
            UID.Text = aToken.UniqueID;



            ResultsLiteral.Text += "<table border=\"1\"  width=\"640\"><tr><th width=\"200\">Type</th><th width=\"240\">Resource</th></tr>";

            TokenHelper tokenHelper = new TokenHelper(identityToken);

            foreach (Claim aClaim in tokenHelper.IdentityClaims)
            {
                ResultsLiteral.Text += "<tr>";
                ResultsLiteral.Text += "<td width=\"200\">" + aClaim.ClaimType + "</td>";
                ResultsLiteral.Text += "<td width=\"240\">" + aClaim.Resource.ToString() + "</td>";
                ResultsLiteral.Text += "</tr>";


            }

            ResultsLiteral.Text += "</table>";
        }
    }
}
