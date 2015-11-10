<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Wizard1_FinishButtonClick(object sender, WizardNavigationEventArgs e)
    {
        Label1.Text = "잭필드 남성 면바지 3종 세트: " + TextBox1.Text + " 개";
        Label2.Text = "진미령 간장 게장: " + TextBox2.Text + " 병";
        Label3.Text = "주소: " + TextBox3.Text;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>제목 없음</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Wizard 예제1</h3>
        <asp:Wizard ID="Wizard1" runat="server" OnFinishButtonClick="Wizard1_FinishButtonClick" CellPadding="5" Width="500">
            <WizardSteps>
                <asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1">
                    <b>물품 주문</b>
                    <p></p>
                    잭필드 남성 면바지 3종 세트: 
                    <asp:TextBox ID="TextBox1" runat="server" Text="1" Columns="3"></asp:TextBox> 개
                    <br />                    
                    진미령 간장 게장:
                    <asp:TextBox ID="TextBox2" runat="server" Text="1" Columns="3"></asp:TextBox> 개
                </asp:WizardStep>
                <asp:WizardStep ID="WizardStep2" runat="server" Title="스텝 2">
                    <b>주소 입력</b>
                    <p></p>
                    주소: <asp:TextBox ID="TextBox3" runat="server" Width="200"></asp:TextBox>
                </asp:WizardStep>
                <asp:WizardStep ID="WizardStep3" runat="server" Title="Step 3" StepType="Complete">
                    <b>최종 주문 확인</b>
                    <p></p>
                    <asp:Label ID="Label1" runat="server" Text=""></asp:Label><br />
                    <asp:Label ID="Label2" runat="server" Text=""></asp:Label><br />                    
                    <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
                </asp:WizardStep>                
            </WizardSteps>
        </asp:Wizard>
    </div>
    </form>
</body>
</html>