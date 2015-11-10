<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Write("다시 게시 되었습니다.!!!");
    }
</script>

<script type="text/javascript">
    function ConfirmPostBack()
    {
        return confirm( '다시 게시 하시겠습니까?' );
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3>Button 예제</h3>
            
            <asp:Button ID="Button1" runat="server" Text="다시 게시" OnClientClick="return ConfirmPostBack()" OnClick="Button1_Click" />
        </div>
    </form>
</body>
</html>