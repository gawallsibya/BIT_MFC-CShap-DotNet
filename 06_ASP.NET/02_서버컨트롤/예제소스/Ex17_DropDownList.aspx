<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            ArrayList ar = new ArrayList();
            ar.Add("Item 1");
            ar.Add("Item 2");
            ar.Add("Item 3");
            DropDownList1.DataSource = ar;
            DropDownList1.DataBind();    
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        string s = "";
        s = "선택한 항목 Index : " + DropDownList1.SelectedIndex.ToString() + "<br>";
        s += "선택한 항목 Text : " + DropDownList1.SelectedItem.Text + "<br>";
        s += "선택한 항목 Value : " + DropDownList1.SelectedItem.Value;
        Label1.Text = s;
    }    
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>DropDownList 예제</h3>
        
        <asp:DropDownList ID="DropDownList1" runat="server">
        </asp:DropDownList>
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>