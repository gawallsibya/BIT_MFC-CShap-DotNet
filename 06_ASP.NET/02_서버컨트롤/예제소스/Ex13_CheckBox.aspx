<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Text = "������ ������ : ";
        if (CheckBox1.Checked == true)        
            Label1.Text += CheckBox1.Text + " ";                   
        if (CheckBox2.Checked == true)        
            Label1.Text += CheckBox2.Text + " ";        
        if (CheckBox3.Checked == true)        
            Label1.Text += CheckBox3.Text;        
    }

    protected void CheckBox4_CheckedChanged(object sender, EventArgs e)
    {
        if (CheckBox4.Checked == true)        
            Label2.Text = "���ϸ��� ���� �մϴ�.";
        else        
            Label2.Text = "���ϸ��� ���� ���� �ʽ��ϴ�.";
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>       
        <h3>CheckBox ����</h3>
        
        <h4>1. �����ϴ� �������� ������.</h4>
        <asp:CheckBox ID="CheckBox1" runat="server" Text="�߱�" /><br />
        <asp:CheckBox ID="CheckBox2" runat="server" Text="�౸" TextAlign="left" /><br />
        <asp:CheckBox ID="CheckBox3" runat="server" Text="��" Enabled="false"/><br />        
        <asp:Button ID="Button1" runat="server" Text="����" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>     
                
        <h4>2. ���ϸ��� ���� ���� üũ</h4>
        <asp:CheckBox ID="CheckBox4" runat="server" Text="���ϸ� ����" AutoPostBack="true" OnCheckedChanged="CheckBox4_CheckedChanged" /><br />
        <asp:Label ID="Label2" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>