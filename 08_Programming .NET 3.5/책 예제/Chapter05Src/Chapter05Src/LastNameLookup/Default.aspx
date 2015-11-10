<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head id="Head1" runat="server">
    <title>Word Wheel</title>
    <script language="javascript" type="text/javascript">
      var xmlHttp
      function showHint(str)
      {
         if (str.length==0)
         { 
            document.getElementById("TextBoxHint").innerHTML=""
            return
         }
         xmlHttp=GetXmlHttpObject()
         if (!xmlHttp || xmlHttp==null)
         {
            alert ("Browser does not support HTTP Request")
            return
         }
         var url="LastNameLookup.aspx"
         url=url+"?q="+str
         xmlHttp.onreadystatechange=stateChanged 
         xmlHttp.open("GET",url,true)
         xmlHttp.send(null)
      }
      
      function stateChanged() 
      { 
         var OK = 200
         if (( xmlHttp.readyState == 4 || 
               xmlHttp.readyState == "complete" ) 
           && xmlHttp.status == OK )
         { 
            document.getElementById("TextBoxHint").innerHTML = 
               xmlHttp.responseText 
         } 
      } 

      function GetXmlHttpObject(handler)
      { 
        var objXMLHttp=null
        if (window.XMLHttpRequest)
        { 
            try 
            {
                objXMLHttp=new XMLHttpRequest()
            } 
            catch (e) 
            {
             // Catch handler here
            }
        }
        else if (window.ActiveXObject)
        {
            try 
            {
                objXMLHttp=new ActiveXObject("Microsoft.XMLHTTP")
            } 
            catch(e) 
            {
              // Catch handler here
            }
        }

        return objXMLHttp

      }
    </script>
    
</head>

<body>
    <form id="form1" runat="server">
     <div>
        <h1>US Census Last Name Lookup</h1><br />
        
        <b>Last name:</b> <asp:TextBox ID="TextBox1" runat="server"
           onkeyup="showHint(this.value)" />
   <p>
    <b><i>Names in the US Census: </i></b> &nbsp;<span id="TextBoxHint"></span>   
   </p> 
  </div>
</form>
</body>
</html>
