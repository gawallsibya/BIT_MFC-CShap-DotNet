<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>RangeValidator ����</h3>
        
        ���ڸ� �Է��ϼ���(1~10 ����) 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
        <asp:RangeValidator ID="RangeValidator1" runat="server" ErrorMessage="1~10 ������ ���ڸ� �Է��ϼ���." ControlToValidate="TextBox1" MaximumValue="10" MinimumValue="1" Type="Integer"></asp:RangeValidator><br />
        <asp:Button ID="Button1" runat="server" Text="Button" />        
    </div>
    </form>
</body>
</html>