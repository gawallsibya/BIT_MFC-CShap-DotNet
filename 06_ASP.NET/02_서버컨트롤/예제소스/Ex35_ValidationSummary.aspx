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
        <h3>ValidationSummary 예제</h3>
        
        아이디 : 
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="아이디를 입력하세요" ControlToValidate="TextBox1" Text="*"></asp:RequiredFieldValidator><br />
        비밀번호 :
        <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="비밀번호를 입력하세요" ControlToValidate="TextBox2" Text="*"></asp:RequiredFieldValidator><br />        
        <asp:Button ID="Button1" runat="server" Text="Button" />
        <p></p>
        <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
    </div>
    </form>
</body>
</html>