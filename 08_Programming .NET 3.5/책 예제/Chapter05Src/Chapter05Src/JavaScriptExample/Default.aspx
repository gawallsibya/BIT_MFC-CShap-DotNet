<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>Simple Partial AJAX example</title>

    <script language="javascript" type="text/javascript">
      function showText(str)
      {
         if (str.length==0)
         {
            document.getElementById("TextBoxContents").innerHTML=""
         
         } 
         else 
         {
           document.getElementById("TextBoxContents").innerHTML=str
         }
      }
    </script>
</head>
<body>
    <form id="form2" runat="server">
        <div>
        <b>What you type here:</b> 
        <asp:TextBox 
            ID="TextBox1" 
            runat="server" 
            onkeyup="showText(this.value)" />
        <p><b><i>Is what you see here: </i></b>  
        <span id="TextBoxContents"></span>        
        </div>
    </form>
</body>
</html>
