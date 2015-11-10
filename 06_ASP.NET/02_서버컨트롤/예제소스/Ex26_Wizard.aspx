<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void Wizard1_FinishButtonClick(object sender, WizardNavigationEventArgs e)
    {
        Label1.Text = "���ʵ� ���� ����� 3�� ��Ʈ: " + TextBox1.Text + " ��";
        Label2.Text = "���̷� ���� ����: " + TextBox2.Text + " ��";
        Label3.Text = "�ּ�: " + TextBox3.Text;
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Wizard ����1</h3>
        <asp:Wizard ID="Wizard1" runat="server" OnFinishButtonClick="Wizard1_FinishButtonClick" CellPadding="5" Width="500">
            <WizardSteps>
                <asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1">
                    <b>��ǰ �ֹ�</b>
                    <p></p>
                    ���ʵ� ���� ����� 3�� ��Ʈ: 
                    <asp:TextBox ID="TextBox1" runat="server" Text="1" Columns="3"></asp:TextBox> ��
                    <br />                    
                    ���̷� ���� ����:
                    <asp:TextBox ID="TextBox2" runat="server" Text="1" Columns="3"></asp:TextBox> ��
                </asp:WizardStep>
                <asp:WizardStep ID="WizardStep2" runat="server" Title="���� 2">
                    <b>�ּ� �Է�</b>
                    <p></p>
                    �ּ�: <asp:TextBox ID="TextBox3" runat="server" Width="200"></asp:TextBox>
                </asp:WizardStep>
                <asp:WizardStep ID="WizardStep3" runat="server" Title="Step 3" StepType="Complete">
                    <b>���� �ֹ� Ȯ��</b>
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