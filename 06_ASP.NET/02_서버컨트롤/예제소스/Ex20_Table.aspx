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
                c.Controls.Add(new LiteralControl("�� " + i.ToString() + ", �� " + k.ToString()));
                r.Cells.Add(c);
            }            
            Table1.Rows.Add(r);
        }
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Table ����</h3>
        
        <asp:Table ID="Table1" runat="server" CellPadding="5" CellSpacing="0" GridLines="both" BorderWidth="1" Caption="Table ���� ����" CaptionAlign="left">
        </asp:Table>        
        <p></p>
        ���� �� : 
        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem Value="1">1 ��</asp:ListItem>
            <asp:ListItem Value="2">2 ��</asp:ListItem>
            <asp:ListItem Value="3">3 ��</asp:ListItem>
            <asp:ListItem Value="4">4 ��</asp:ListItem>
        </asp:DropDownList>&nbsp;&nbsp;&nbsp;
        ���� ��:
        <asp:DropDownList ID="DropDownList2" runat="server">
            <asp:ListItem Value="1">1 ��</asp:ListItem>
            <asp:ListItem Value="2">2 ��</asp:ListItem>
            <asp:ListItem Value="3">3 ��</asp:ListItem>
            <asp:ListItem Value="4">4 ��</asp:ListItem>
        </asp:DropDownList>        
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="���̺� ����" OnClick="Button1_Click" />        
    </div>
    </form>
</body>
</html>