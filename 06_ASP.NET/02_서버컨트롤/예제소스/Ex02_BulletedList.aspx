<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    
    protected void BulletedList3_Click(object sender, BulletedListEventArgs e)
    {
        Response.Write("선택한 목록 번호 : " + e.Index.ToString()
            + "<br>선택한 목록 Value : " + BulletedList3.Items[e.Index].Value
            + "<br>선택한 목록 Text : " + BulletedList3.Items[e.Index].Text);
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr align="center">
                    <td>
                        <h3>Disc</h3>
                        <asp:BulletedList ID="BulletedList1" runat="server">
                            <asp:ListItem>Item #1</asp:ListItem>
                            <asp:ListItem>Item #2</asp:ListItem>
                            <asp:ListItem>Item #3</asp:ListItem>
                            <asp:ListItem>Item #4</asp:ListItem>
                        </asp:BulletedList>
                    </td>
                    <td>
                        <h3>Circle</h3>
                        <asp:BulletedList ID="BulletedList2" BulletStyle="Circle" DisplayMode="HyperLink"
                            runat="server">
                            <asp:ListItem Value="http://www.naver.com">Item #1</asp:ListItem>
                            <asp:ListItem Value="http://www.empas.com">Item #2</asp:ListItem>
                            <asp:ListItem Value="http://www.daum.net">Item #3</asp:ListItem>
                            <asp:ListItem Value="http://www.yahoo.co.kr">Item #4</asp:ListItem>
                        </asp:BulletedList>
                    </td>
                    <td>
                        <h3>Square</h3>
                        <asp:BulletedList ID="BulletedList3" BulletStyle="Square" DisplayMode="LinkButton"
                            runat="server" OnClick="BulletedList3_Click">
                            <asp:ListItem Value="Item #1 Value">Item #1</asp:ListItem>
                            <asp:ListItem>Item #2</asp:ListItem>
                            <asp:ListItem>Item #3</asp:ListItem>
                            <asp:ListItem>Item #4</asp:ListItem>
                        </asp:BulletedList>
                    </td>
                    <td>
                        <h3>Numbered</h3>
                        <asp:BulletedList ID="BulletedList4" BulletStyle="Numbered" FirstBulletNumber="3"
                            runat="server">
                            <asp:ListItem>Item #1</asp:ListItem>
                            <asp:ListItem>Item #2</asp:ListItem>
                            <asp:ListItem>Item #3</asp:ListItem>
                            <asp:ListItem>Item #4</asp:ListItem>
                        </asp:BulletedList>
                    </td>
                </tr>                
            </table>
        </div>
    </form>
</body>
</html>