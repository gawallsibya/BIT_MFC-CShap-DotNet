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
        <h3>ValidationSummary ����</h3>
        
        ���̵� : 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="���̵� �Է��ϼ���" ControlToValidate="TextBox1" Text="*"></asp:RequiredFieldValidator><br />
        ��й�ȣ :
        <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="��й�ȣ�� �Է��ϼ���" ControlToValidate="TextBox2" Text="*"></asp:RequiredFieldValidator><br />        
        <asp:Button ID="Button1" runat="server" Text="Button" />
        <p></p>
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
    </div>
    </form>
</body>
</html>