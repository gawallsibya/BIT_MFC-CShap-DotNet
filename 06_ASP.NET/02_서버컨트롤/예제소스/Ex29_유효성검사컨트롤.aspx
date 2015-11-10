<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)        
            Label1.Text = "현재 페이지의 모든 유효성 검사가 완료 되었습니다.";
        else        
            Label1.Text = "유효하지 않은 정보가 있습니다.";
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>RequiredFieldValidator 예제1</h3>
        
        이름 : <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox> <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="이름을 입력하세요" ControlToValidate="TextBox1"></asp:RequiredFieldValidator><br />
        비밀번호 : <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox> <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="비밀번호를 입력하세요" ControlToValidate="TextBox2"></asp:RequiredFieldValidator><br />
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" />
        <p></p>
        <asp:Label ID="Label1" runat="server"></asp:Label>
    </div>
    </form>
</body>
</html>