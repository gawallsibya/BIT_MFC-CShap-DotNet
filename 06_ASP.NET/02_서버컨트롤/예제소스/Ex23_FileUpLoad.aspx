<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        if (FileUpload1.HasFile)
        {
            FileUpload1.SaveAs("C:\\Uploads\\" + FileUpload1.FileName);
            Label1.Text = "���ϸ� : " + FileUpload1.FileName + "<br>������ Ÿ�� : " + FileUpload1.PostedFile.ContentType + "<br>���� ������ : " + FileUpload1.PostedFile.ContentLength;
        }
        else
        {
            Label1.Text = "���ε��� ������ �������� �ʽ��ϴ�.";
        }
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>FileUpload ����</h3>
        
        <asp:FileUpload ID="FileUpload1" runat="server" /><br />
        <asp:Button ID="Button1" runat="server" Text="����÷��" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>