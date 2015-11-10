<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Page_Load(object sender, EventArgs e)
    {
        if (DropDownList1.SelectedItem.Value == "0")        
            Image1.ImageUrl = "~/Images/before.jpg";
        else        
            Image1.ImageUrl = "~/Images/after.jpg";                    
        Image1.AlternateText = DropDownList1.SelectedItem.Text;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Á¦¸ñ ¾øÀ½</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Image ¿¹Á¦</h3>
        
        <asp:Image ID="Image1" runat="server" />
        
        <p></p>
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True">
            <asp:ListItem Value="0">ÃÖÈ«¸¸°ú ½Î¿ì±âÀüÀÇ ¹ä¼¥</asp:ListItem>
            <asp:ListItem Value="1">ÃÖÈ«¸¸°ú ½Î¿î ÈÄÀÇ ¹ä¼¥</asp:ListItem>
        </asp:DropDownList>
    </div>
    </form>
</body>
</html>