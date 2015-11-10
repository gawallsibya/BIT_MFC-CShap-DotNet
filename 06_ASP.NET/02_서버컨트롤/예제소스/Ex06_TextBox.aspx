<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Write(TextBox1.Text + "<br>");
        Response.Write(TextBox2.Text + "<br>");
        Response.Write(TextBox3.Text + "<br>");
        Response.Write(TextBox4.Text + "<br>");
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>TextBox 예제</h3>
        
        <table>
            <tr>
                <td>이름 : </td>
                <td><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox></td>
            </tr>
            <tr>
                <td>아이디 : </td>
                <td><asp:TextBox ID="TextBox2" runat="server" MaxLength="12"></asp:TextBox></td>
            </tr>
            <tr>
                <td>비밀번호 : </td>
                <td><asp:TextBox ID="TextBox3" runat="server" TextMode="password" MaxLength="12"></asp:TextBox></td>
            </tr>
            <tr>
                <td>기타 : </td>
                <td><asp:TextBox ID="TextBox4" runat="server" TextMode="multiLine" Rows="12" Columns="40" ></asp:TextBox></td>
            </tr>
        </table>        
        <p></p>
        <asp:Button ID="Button1" runat="server" Text="확인" OnClick="Button1_Click" />
    </div>
    </form>
</body>
</html>