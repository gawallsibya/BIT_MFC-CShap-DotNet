<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
</script>

<script type="text/javascript">
    function MultipleOfThree(source, arguments)
    {
        var iValue = arguments.Value;
        
        if (iValue % 3 == 0)        
            arguments.IsValid = true;
        else 
            arguments.IsValid = false;   
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>   
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>CustomValidator ����</h3>
        
        3�� ����� �Է� �ϼ��� 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <p></p>
        <asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="3�� ����� �ƴմϴ�." ClientValidationFunction="MultipleOfThree" ControlToValidate="TextBox1"></asp:CustomValidator>
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="Button" />
    </div>
    </form>
</body>
</html>