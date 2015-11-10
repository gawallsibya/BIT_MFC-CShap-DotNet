<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void RadioButton1_CheckedChanged(object sender, EventArgs e)
    {
        CheckBoxList1.RepeatLayout = RepeatLayout.Table;
    }

    protected void RadioButton2_CheckedChanged(object sender, EventArgs e)
    {
        CheckBoxList1.RepeatLayout = RepeatLayout.Flow;
    }

    protected void RadioButton3_CheckedChanged(object sender, EventArgs e)
    {
        CheckBoxList1.RepeatDirection = RepeatDirection.Vertical;
    }

    protected void RadioButton4_CheckedChanged(object sender, EventArgs e)
    {
        CheckBoxList1.RepeatDirection = RepeatDirection.Horizontal;
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        string s = "선택한 항목:<br>";
        for (int i = 0; i < CheckBoxList1.Items.Count; i++)
        {
            if (CheckBoxList1.Items[i].Selected == true)
            {
                s += CheckBoxList1.Items[i].Text + "<br>";
            }
        }
        Label1.Text = s;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>CheckBoxList 예제</h3>
        
        RepeateLayout: <asp:RadioButton ID="RadioButton1" runat="server" Checked="true" Text="Table" GroupName="Layout" AutoPostBack="True" OnCheckedChanged="RadioButton1_CheckedChanged" />
        <asp:RadioButton ID="RadioButton2" runat="server" Text="Flow" GroupName="Layout" AutoPostBack="True" OnCheckedChanged="RadioButton2_CheckedChanged" /><br />
        RepeateDirection: <asp:RadioButton ID="RadioButton3" runat="server" Checked="true" Text="Vertical" GroupName="Direction" AutoPostBack="True" OnCheckedChanged="RadioButton3_CheckedChanged" />
        <asp:RadioButton ID="RadioButton4" runat="server" Text="Horizontal" GroupName="Direction" AutoPostBack="True" OnCheckedChanged="RadioButton4_CheckedChanged" />
        <p></p>
        <asp:CheckBoxList ID="CheckBoxList1" runat="server">
            <asp:ListItem Value="1">Item 1</asp:ListItem>
            <asp:ListItem Value="2" Text="Item 2"></asp:ListItem>
            <asp:ListItem Value="3" Enabled="false">Item3</asp:ListItem>
            <asp:ListItem Value="4" Selected="true">Item 4</asp:ListItem>
        </asp:CheckBoxList>        
        <p></p>        
        <asp:Button ID="Button1" runat="server" Text="확인" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>        
    </div>
    </form>
</body>
</html>