<%@ Page Title="홈 페이지" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        ASP.NET 시작
    </h2>
    <p>
        <asp:TextBox ID="txt_Insert" runat="server"></asp:TextBox>
        <asp:Button ID="btn_Insert" runat="server" onclick="btn_Insert_Click" 
            Text="입력" />
    </p>
    <p>
        <asp:Label ID="Label_text" runat="server"></asp:Label>
        <asp:Button ID="btn_Nextpage" runat="server" 
            PostBackUrl="~/Page02.aspx" Text="다음페이지" onclick="btn_Insert_Click" />
    </p>
    </asp:Content>
