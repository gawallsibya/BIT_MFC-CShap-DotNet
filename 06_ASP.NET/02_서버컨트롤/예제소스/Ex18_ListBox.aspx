<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Button1_Click(object sender, EventArgs e)
    {
        string s = "선택한 항목: ";
        for (int i = 0; i < ListBox1.Items.Count; i++)
        {
            if (ListBox1.Items[i].Selected == true)
            {
                s += ListBox1.Items[i].Text + " ";
            }
        }
        Label1.Text = s;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>ListBox 예제</h3>
        
        <asp:ListBox ID="ListBox1" runat="server" SelectionMode="multiple">
            <asp:ListItem Value="1" Text="Item 1"></asp:ListItem>
            <asp:ListItem Value="2" Text="Item 2"></asp:ListItem>
            <asp:ListItem Value="3" Text="Item 3"></asp:ListItem>
        </asp:ListBox>
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>