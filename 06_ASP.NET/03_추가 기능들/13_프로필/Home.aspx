<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" Title="���� ����" %>

<script runat="server">
    protected void Page_Load(object sender, EventArgs e)
    {   
        if (!Page.IsPostBack)
        {   
            StyleContainer.Style.Add(HtmlTextWriterStyle.BackgroundColor, Profile.MainBackColor);
            Calendar1.Visible = Profile.EnableCalendar;
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/secured/SetProfile.aspx");
    }
</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <div id="StyleContainer" runat="server">
        ���� ������ �Դϴ�.<p></p>
        <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar><p></p>
        <asp:Button ID="Button1" runat="server" Text="����� ���� �������� �̵�" OnClick="Button1_Click" />
    </div>
</asp:Content>