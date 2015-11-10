<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>


<%@ Register assembly="AjaxControlToolkit" namespace="AjaxControlToolkit" tagprefix="cc1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>178212 + 184112 = 192212</title>
    <link href="TextBoxWatermarkStyle.css" rel="stylesheet" type="text/css" />
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
        <br />
    
        <asp:TextBox ID="TextBox1" runat="server" CssClass="unwatermarked"></asp:TextBox>
        <cc1:TextBoxWatermarkExtender ID="TextBox1_TextBoxWatermarkExtender" 
            runat="server" Enabled="True" TargetControlID="TextBox1" 
            WatermarkText="Click here to enter date" WatermarkCssClass="watermarked">
        </cc1:TextBoxWatermarkExtender>
        <cc1:CalendarExtender ID="TextBox1_CalendarExtender" runat="server" 
            Enabled="True" TargetControlID="TextBox1" Format="MMMM d, yyyy">
        </cc1:CalendarExtender>
    
    </div>
    </form>
</body>
</html>
