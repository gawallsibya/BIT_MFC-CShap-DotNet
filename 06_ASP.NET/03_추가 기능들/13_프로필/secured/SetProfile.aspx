<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" Title="���� ����" %>

<script runat="server">
    protected void Page_Load(object sender, EventArgs e)
    {   
        if (!Page.IsPostBack)
        {
            ListItem i1 = DropDownList1.Items.FindByValue(Profile.MainBackColor);
            if (i1 != null)            
                i1.Selected = true;            

            if (Profile.EnableCalendar) // Ķ������ ����Ѵٸ�            
                RadioButton1.Checked = true;
            else // Ķ������ ������� �ʴ´ٸ�
                RadioButton2.Checked = true;
        }        
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Profile.MainBackColor = DropDownList1.SelectedItem.Value;
        if (RadioButton1.Checked)
            Profile.EnableCalendar = true; // Ķ���� ���
        else
            Profile.EnableCalendar = false; // Ķ���� �̻��
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/Home.aspx");        
    }
</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    ���� ������ ��� ���� : 
    <asp:DropDownList ID="DropDownList1" runat="server">
        <asp:ListItem Value="">�⺻</asp:ListItem>
        <asp:ListItem Value="red">Red</asp:ListItem>
        <asp:ListItem Value="green">Green</asp:ListItem>
        <asp:ListItem Value="blue">Blue</asp:ListItem>
    </asp:DropDownList><br />
    Ķ���� ��� ���� :
    <asp:RadioButton ID="RadioButton1" runat="server" Text="���" GroupName="CheckCalendar" Checked="true" /><asp:RadioButton ID="RadioButton2" runat="server" Text="�̻��" GroupName="CheckCalendar" /><p></p>    
    <asp:Button ID="Button1" runat="server" Text="���� ���� ����" OnClick="Button1_Click" />
    <asp:Button ID="Button2" runat="server" Text="���� ������..." OnClick="Button2_Click" />
</asp:Content>