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
        <h3>RegularExpressionValidator ����</h3>
        
        �����ȣ : 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox> ��) 123-456
        <p></p>
        <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ErrorMessage="�����ȣ ������ �߸��Ǿ����ϴ�." ValidationExpression="\d{3}-\d{3}" ControlToValidate="TextBox1" SetFocusOnError="True"></asp:RegularExpressionValidator>
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="Button" />        
    </div>
    </form>
</body>
</html>