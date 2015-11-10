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
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="http://www.microsoft.co.kr" Text="한국마이크로소프트 웹 사이트로 이동"></asp:HyperLink>
        
        <p></p>
        <asp:HyperLink ID="HyperLink2" runat="server" ImageUrl="~/Images/microsoft.gif" NavigateUrl="http://www.microsoft.co.kr" Target="_blank"></asp:HyperLink>
    </div>
    </form>
</body>
</html>