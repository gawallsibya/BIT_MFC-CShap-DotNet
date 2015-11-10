<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    
    protected void Button1_Click(object sender, EventArgs e)
    {
        Label3.Text = TextBox1.Text;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Label 예제</h3>
        
        <asp:Label ID="Label1" runat="server" Text="이름(n)" AccessKey="n" AssociatedControlID="TextBox1"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />        
        <asp:Label ID="Label2" runat="server" AccessKey="o" AssociatedControlID="Button1"></asp:Label>
        <asp:Button ID="Button1" runat="server" Text="Button(o)" OnClick="Button1_Click" />
        <p></p>
        <asp:Label ID="Label3" runat="server"></asp:Label>
    </div>
    </form>
</body>
</html>