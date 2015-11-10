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
    <title>제목 없음</title>   
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>CustomValidator 예제</h3>
        
        3의 배수를 입력 하세요 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <p></p>
        <asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="3의 배수가 아닙니다." ClientValidationFunction="MultipleOfThree" ControlToValidate="TextBox1"></asp:CustomValidator>
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="Button" />
    </div>
    </form>
</body>
</html>