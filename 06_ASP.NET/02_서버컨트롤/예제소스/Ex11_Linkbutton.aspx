<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void LinkButton1_Click(object sender, EventArgs e)
    {
        Label1.Text = LinkButton1.ID + "�� Ŭ�� �Ǿ����ϴ�.";
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3>LinkButton ����</h3>
            
            <asp:LinkButton ID="LinkButton1" runat="server" Text="�ٽ� �Խ�!!!" OnClick="LinkButton1_Click"></asp:LinkButton>
            <p></p>
            <asp:Label ID="Label1" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>