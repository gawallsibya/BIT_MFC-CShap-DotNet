<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    
    protected void Page_Load(object sender, EventArgs e)
    {
        TextBox TextBox1 = new TextBox();
        TextBox1.Text = "텍스트 박스1";
        PlaceHolder1.Controls.Add(TextBox1);

        TextBox TextBox2 = new TextBox();
        TextBox2.Text = "텍스트 박스2";
        TextBox2.TextMode = TextBoxMode.MultiLine;
        TextBox2.Rows = 3;
        PlaceHolder1.Controls.Add(TextBox2);

        Button Button1 = new Button();
        Button1.Text = "버튼1";
        PlaceHolder1.Controls.Add(Button1);
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>PlaceHolder 예제</h3>
        
        <asp:PlaceHolder ID="PlaceHolder1" runat="server"></asp:PlaceHolder>
    </div>
    </form>
</body>
</html>