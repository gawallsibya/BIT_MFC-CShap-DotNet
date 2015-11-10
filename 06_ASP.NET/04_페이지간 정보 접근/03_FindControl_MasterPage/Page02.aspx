<%@ Page Title="" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true" CodeFile="Page02.aspx.cs" Inherits="Page02" %>
<%@ PreviousPageType VirtualPath="~/Default.aspx" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" Runat="Server">

    <p>
    <br />
</p>
<p>
    <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    <asp:Button ID="Button1" runat="server" onclick="Page_Load" Text="Button" 
        PostBackUrl="~/Page03.aspx" />
</p>
<p>
</p>
</asp:Content>

