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
        <h3>Literal 예제</h3>
        
        <asp:Literal ID="Literal1" runat="server" Text="<strong>test</strong>"></asp:Literal><br />
        <asp:Literal ID="Literal2" runat="server" Text="<strong>test</strong>" Mode="encode"></asp:Literal>
    </div>
    </form>
</body>
</html>