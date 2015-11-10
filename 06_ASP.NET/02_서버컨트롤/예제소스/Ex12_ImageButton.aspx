<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        Label1.Text = "X : " + e.X.ToString();
        Label2.Text = "Y : " + e.Y.ToString();
    }    

    protected void ImageButton2_Click(object sender, ImageClickEventArgs e)
    {
        Label3.Text = "'확인' 버튼이 클릭되었습니다.";
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>ImageButton 예제</h3>        
        
        <table>
            <tr>
                <td>
                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="~/Images/ImageButton1.gif" OnClick="ImageButton1_Click" />
                </td>
                <td>
                    <asp:Label ID="Label1" runat="server" Text="X : "></asp:Label><br />
                    <asp:Label ID="Label2" runat="server" Text="Y : "></asp:Label>
                </td>
                
            </tr>
            <tr>
                <td colspan="2">&nbsp;</td>
            </tr>
            <tr>                
                <td>
                    <asp:ImageButton ID="ImageButton2" runat="server" ImageUrl="~/Images/ImageButton2.gif" OnClick="ImageButton2_Click" />
                </td>
                <td>
                    <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>