<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Write("�ٽ� �Խ� �Ǿ����ϴ�.!!!");
    }
</script>

<script type="text/javascript">
    function ConfirmPostBack()
    {
        return confirm( '�ٽ� �Խ� �Ͻðڽ��ϱ�?' );
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3>Button ����</h3>
            
            <asp:Button ID="Button1" runat="server" Text="�ٽ� �Խ�" OnClientClick="return ConfirmPostBack()" OnClick="Button1_Click" />
        </div>
    </form>
</body>
</html>