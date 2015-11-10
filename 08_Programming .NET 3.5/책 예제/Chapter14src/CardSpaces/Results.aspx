<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Results.aspx.cs" Inherits="Results" ValidateRequest="false"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>Programming .NET 3.5 :: CardSpaces Results</title>
    <style type="text/css">
        .cardspaceTable
        {
            font-family: Verdana;
            font-size: x-small;
            font-weight: normal;
        }
    </style>
</head>
<body>

    <form id="identityForm" runat="server">
    <div class="cardspaceTable">
        The Identity Card provided contains the following information:<br />
        <br />
        Name: <asp:Label ID="FirstName" runat="server" Text=""/> <asp:Label ID="LastName" runat="server" Text="" /><br />
        City: <asp:Label ID="City" runat="server" Text=""/><br />
        Country: <asp:Label ID="Country" runat="server" Text=""/><br />
        Email: <asp:Label ID="Email" runat="server" Text=""/><br />
        Unique ID: <asp:Label ID="UID" runat="server" Text=""/><br />
        <br /><br />In the form of these decrypted claims:</br>
        <asp:Literal ID="ResultsLiteral" runat="server" />
    </div>
    </form>

</body>
</html>

