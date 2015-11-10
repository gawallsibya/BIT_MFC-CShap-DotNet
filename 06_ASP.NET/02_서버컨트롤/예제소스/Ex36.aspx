<%@ Page Language="C#" %>
<%@ Register Src="Top.ascx" TagName="Top" TagPrefix="uc1" %>
<%@ Register Src="Left.ascx" TagName="Left" TagPrefix="uc2" %>
<%@ Register Src="Bottom.ascx" TagName="Bottom" TagPrefix="uc3" %>

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
        <table border="1" width="500" style="height: 350px;">
            <tr>
                <td colspan="2" style="height: 80px;">
                    <uc1:Top ID="Top1" runat="server" />
                </td>
            </tr>
            <tr>
                <td style="height: 190px; width: 100px;">
                    <uc2:Left ID="Left1" runat="server" />
                </td>
                <td style="width: 300px;">
                </td>
            </tr>
            <tr>
                <td colspan="2" style="height: 80px;">
                    <uc3:Bottom ID="Bottom1" runat="server" />
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>