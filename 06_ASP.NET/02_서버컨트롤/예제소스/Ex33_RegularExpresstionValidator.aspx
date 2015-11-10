<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>RegularExpressionValidator 예제</h3>
        
        우편번호 : 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox> 예) 123-456
        <p></p>
        <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ErrorMessage="우편번호 형식이 잘못되었습니다." ValidationExpression="\d{3}-\d{3}" ControlToValidate="TextBox1" SetFocusOnError="True"></asp:RegularExpressionValidator>
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="Button" />        
    </div>
    </form>
</body>
</html>