<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Button1_Click(object sender, EventArgs e)
    {
        if (FileUpload1.HasFile)
        {
            FileUpload1.SaveAs("C:\\Uploads\\" + FileUpload1.FileName);
            Label1.Text = "파일명 : " + FileUpload1.FileName + "<br>콘텐츠 타입 : " + FileUpload1.PostedFile.ContentType + "<br>파일 사이즈 : " + FileUpload1.PostedFile.ContentLength;
        }
        else
        {
            Label1.Text = "업로드할 파일이 존재하지 않습니다.";
        }
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>FileUpload 예제</h3>
        
        <asp:FileUpload ID="FileUpload1" runat="server" /><br />
        <asp:Button ID="Button1" runat="server" Text="파일첨부" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
    </div>
    </form>
</body>
</html>