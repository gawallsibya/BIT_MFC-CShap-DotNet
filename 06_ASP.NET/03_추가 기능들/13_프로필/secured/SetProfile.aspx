<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" Title="제목 없음" %>

<script runat="server">
    protected void Page_Load(object sender, EventArgs e)
    {   
        if (!Page.IsPostBack)
        {
            ListItem i1 = DropDownList1.Items.FindByValue(Profile.MainBackColor);
            if (i1 != null)            
                i1.Selected = true;            

            if (Profile.EnableCalendar) // 캘린더를 사용한다면            
                RadioButton1.Checked = true;
            else // 캘린더를 사용하지 않는다면
                RadioButton2.Checked = true;
        }        
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Profile.MainBackColor = DropDownList1.SelectedItem.Value;
        if (RadioButton1.Checked)
            Profile.EnableCalendar = true; // 캘린더 사용
        else
            Profile.EnableCalendar = false; // 캘린더 미사용
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/Home.aspx");        
    }
</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    메인 페이지 배경 색깔 : 
    <asp:DropDownList ID="DropDownList1" runat="server">
        <asp:ListItem Value="">기본</asp:ListItem>
        <asp:ListItem Value="red">Red</asp:ListItem>
        <asp:ListItem Value="green">Green</asp:ListItem>
        <asp:ListItem Value="blue">Blue</asp:ListItem>
    </asp:DropDownList><br />
    캘런더 사용 여부 :
    <asp:RadioButton ID="RadioButton1" runat="server" Text="사용" GroupName="CheckCalendar" Checked="true" /><asp:RadioButton ID="RadioButton2" runat="server" Text="미사용" GroupName="CheckCalendar" /><p></p>    
    <asp:Button ID="Button1" runat="server" Text="설정 상태 저장" OnClick="Button1_Click" />
    <asp:Button ID="Button2" runat="server" Text="메인 페이지..." OnClick="Button2_Click" />
</asp:Content>