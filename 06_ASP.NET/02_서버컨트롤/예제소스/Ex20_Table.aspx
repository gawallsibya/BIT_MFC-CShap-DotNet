<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        int iRows = int.Parse(DropDownList1.SelectedItem.Value);
        int iCells = int.Parse(DropDownList2.SelectedItem.Value);
        
        for (int i=0; i<iRows; i++) 
        {        
            TableRow r = new TableRow();            
            for (int k=0; k<iCells; k++) 
            {
                TableCell c = new TableCell();
                c.Controls.Add(new LiteralControl("青 " + i.ToString() + ", 伎 " + k.ToString()));
                r.Cells.Add(c);
            }            
            Table1.Rows.Add(r);
        }
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>力格 绝澜</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Table 抗力</h3>
        
        <asp:Table ID="Table1" runat="server" CellPadding="5" CellSpacing="0" GridLines="both" BorderWidth="1" Caption="Table 悼利 积己" CaptionAlign="left">
        </asp:Table>        
        <p></p>
        青狼 荐 : 
        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem Value="1">1 青</asp:ListItem>
            <asp:ListItem Value="2">2 青</asp:ListItem>
            <asp:ListItem Value="3">3 青</asp:ListItem>
            <asp:ListItem Value="4">4 青</asp:ListItem>
        </asp:DropDownList>&nbsp;&nbsp;&nbsp;
        伎狼 荐:
        <asp:DropDownList ID="DropDownList2" runat="server">
            <asp:ListItem Value="1">1 伎</asp:ListItem>
            <asp:ListItem Value="2">2 伎</asp:ListItem>
            <asp:ListItem Value="3">3 伎</asp:ListItem>
            <asp:ListItem Value="4">4 伎</asp:ListItem>
        </asp:DropDownList>        
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="抛捞喉 积己" OnClick="Button1_Click" />        
    </div>
    </form>
</body>
</html>