<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Submit1_ServerClick(object sender, EventArgs e)
    {        
        Label1.Text = Text1.Value + "<br>" 
            + Password1.Value + "<br>" 
            + (Radio1.Checked == true ? "��" : "��") + "<br>" 
            + (Checkbox1.Checked == true ? "���ϸ� ����" : "���ϸ� �̰���") + "<br>";
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>HTML ��Ʈ�� ����</h3>
        
        ���̵� : <input id="Text1" type="text" runat="server" /><br />
        ��й�ȣ : <input id="Password1" type="password" runat="server" /><br />       
        ���� : ��<input id="Radio1" type="radio" name="gender" runat="server" checked />
        ��<input id="Radio2" type="radio" name="gender" runat="server" /><br />
        ���ϸ� ����<input id="Checkbox1" type="checkbox" runat="server" />
        <p></p>
        <input id="Submit1" type="submit" value="Ȯ��" runat="server" onserverclick="Submit1_ServerClick" />
        <p></p>
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>