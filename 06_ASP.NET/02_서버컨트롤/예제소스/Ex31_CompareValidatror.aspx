<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">    
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>CompareValidator 예제</h3>
        
        비밀번호 : 
        <asp:TextBox ID="TextBox1" runat="server" TextMode="Password"></asp:TextBox>&nbsp;
        <asp:CompareValidator ID="CompareValidator1" runat="server" ErrorMessage="비밀번호가 일치하지 않습니다." ControlToCompare="TextBox2" ControlToValidate="TextBox1"></asp:CompareValidator><br />
        비밀번호 확인 : 
        <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox><br />
        <asp:Button ID="Button1" runat="server" Text="Button" />
    </div>
    </form>
</body>
</html>