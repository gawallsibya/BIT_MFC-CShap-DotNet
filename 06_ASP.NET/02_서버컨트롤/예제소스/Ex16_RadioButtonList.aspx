<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        Label1.Text = RadioButtonList1.SelectedIndex.ToString() + "번째 항목 Value: " + RadioButtonList1.SelectedItem.Value + ", Text: " + RadioButtonList1.SelectedItem.Text;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>RadioButtonList 예제</h3>
        
        <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged">
            <asp:ListItem Value="A" Selected="true">Item 1</asp:ListItem>
            <asp:ListItem Value="B">Item 2</asp:ListItem>
            <asp:ListItem Value="C">Item 3</asp:ListItem>
        </asp:RadioButtonList>        
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>