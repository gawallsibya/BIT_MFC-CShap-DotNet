<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" AutoEventWireup="true" CodeBehind="PeopleLister.aspx" Inherits="MvcApplication.Views.Person.PeopleLister"%>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContentPlaceHolder" runat="server">

        <h2>People In Our Database</h2>

   <ul>
    
        <% foreach (var person in ViewData.People) { %>
    
            <li>
                <%=person.PersonName%> 
            </li>
    
        <% } %>
    
    </ul>
    <%= Html.ActionLink("Add New Person", new { Action="New" }) %>
</asp:Content>