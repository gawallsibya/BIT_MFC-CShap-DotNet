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
        <h3>RequiredFieldValidator ����2</h3>
        
        �̸� : <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="�̸��� �Է��ϼ���." ControlToValidate="TextBox1" ValidationGroup="Name" SetFocusOnError="True"></asp:RequiredFieldValidator><br />        
        <asp:Button ID="Button1" runat="server" Text="Button1" ValidationGroup="Name" />
        <p></p>        
        ��� : <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem Value="">-��� ����-</asp:ListItem>
            <asp:ListItem Value="1">����</asp:ListItem>
            <asp:ListItem Value="2">��ü����</asp:ListItem>
            <asp:ListItem Value="3">��� ����� ���</asp:ListItem>
        </asp:DropDownList>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="��̸� �����ϼ���." ControlToValidate="DropDownList1" ValidationGroup="Hobby" SetFocusOnError="True"></asp:RequiredFieldValidator><br />
        <asp:Button ID="Button2" runat="server" Text="Button2" ValidationGroup="Hobby" />        
    </div>
    </form>
</body>
</html>