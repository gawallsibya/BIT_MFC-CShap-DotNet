<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Text = "������ ������ : ";
        if (RadioButton1.Checked == true)
            Label1.Text = RadioButton1.Text;
        else if (RadioButton2.Checked == true)
            Label1.Text = RadioButton2.Text;
        else if (RadioButton3.Checked == true)
            Label1.Text = RadioButton3.Text;
    } 
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>       
        <h3>RadioButton ����</h3>
        
        <h4>* �����ϴ� �������� ������.</h4>
        <asp:RadioButton ID="RadioButton1" runat="server" GroupName="Sports" Text="�߱�" /><br />
        <asp:RadioButton ID="RadioButton2" runat="server" GroupName="Sports" Text="�౸" /><br />
        <asp:RadioButton ID="RadioButton3" runat="server" GroupName="Sports" Text="��" Enabled="False" /><br />
        <asp:Button ID="Button1" runat="server" Text="����" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>     
    </div>
    </form>
</body>
</html>