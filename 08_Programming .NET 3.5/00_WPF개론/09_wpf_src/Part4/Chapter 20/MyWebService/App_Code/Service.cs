using System;
using System.Collections.Generic;
using System.Web;
using System.Web.Services;

/// <summary>
/// Service1의 요약 설명입니다.
/// </summary>
[WebService(Namespace = "http://tempuri.org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
[System.ComponentModel.ToolboxItem(false)]
public class MyService : System.Web.Services.WebService
{

    [WebMethod]
    public List<string> GetNames()
    {
        List<String> names = new List<string>();
        names.Add("King");
        names.Add("Solomon");
        names.Add("Tomom");
        names.Add("Bath");
        return names;
    }

}

