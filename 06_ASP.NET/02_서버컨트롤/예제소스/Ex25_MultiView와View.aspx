<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        MultiView1.ActiveViewIndex = DropDownList1.SelectedIndex;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>MultiView and View 예제</h3>
        
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
            <asp:ListItem>View 1</asp:ListItem>
            <asp:ListItem>View 2</asp:ListItem>            
        </asp:DropDownList>        
        <hr /><br />
        <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="0">
            <asp:View ID="View1" runat="server">
                View 1<br />
                <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                <asp:Button ID="Button1" runat="server" Text="Button" />                
            </asp:View>
            <asp:View ID="View2" runat="server">
                View 2<br />
                <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/microsoft.gif" />
            </asp:View>
        </asp:MultiView>
    </div>
    </form>
</body>
</html>