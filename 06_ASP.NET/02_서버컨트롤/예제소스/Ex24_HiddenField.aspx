<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (HiddenField1.Value == "")        
            HiddenField1.Value = "0";        
        
        int iNum = int.Parse(HiddenField1.Value) + 1; // 기존의 값에 1을 더함.
        HiddenField1.Value = iNum.ToString(); // 연산한 결과를 다시 HiddenField에 저장(상태 저장)
        Label1.Text = "버튼 클릭 수 : " + HiddenField1.Value;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>HiddenField 예제</h3>
        
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" /><br />
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        <asp:HiddenField ID="HiddenField1" runat="server"/>
    </div>
    </form>
</body>
</html>