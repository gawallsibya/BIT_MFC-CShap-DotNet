<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" AutoEventWireup="true" CodeBehind="New.aspx.cs" Inherits="MvcApplication.Views.Person.New" %>

<asp:Content ID="PageContent" ContentPlaceHolderID="MainContentPlaceHolder" runat="server">

        <h2>Add a Person to our Database</h2>

 <form action="/Person/NewInsert" method="post">
    
        <table>

            <tr>
                <td>Name:</td>
                <td><input id="PersonName" type="text" name="PersonName" /></td>
            </tr>
            <tr>
                <td>Shipping Preference:</td>
                <td><%=Html.Select("IDShippingMethod", ViewData.Shippers)%></td>
            </tr>
        </table>

        <p></p>
        
        <input type="submit" value="Save" />

    </form>

</asp:Content>