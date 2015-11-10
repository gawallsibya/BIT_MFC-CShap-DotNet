<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">   
    
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        Calendar1.SelectionMode = (CalendarSelectionMode)DropDownList1.SelectedIndex;
        if (Calendar1.SelectionMode == CalendarSelectionMode.None)
            Calendar1.SelectedDates.Clear();
    }
    
    protected void Calendar1_SelectionChanged(object sender, EventArgs e)
    {
        switch (Calendar1.SelectedDates.Count)
        {
            case (0):   //None
                Response.Write("� ���ڵ� ���õ��� �ʾҽ��ϴ�.");
                break;
            case (1):   //Day
                Response.Write("������ ���� " + Calendar1.SelectedDate.ToShortDateString());
                break;
            case (7):   //Week
                Response.Write("������ ���� ���� ���� " + Calendar1.SelectedDate.ToShortDateString());
                break;
            default:    //Month
                Response.Write("������ ���� ���� ���� " + Calendar1.SelectedDate.ToShortDateString());
                break;
        }
    }    
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Calendar�� SelectionChanged �̺�Ʈ�� ����� ����</h3>
    
        SelectionMode ���� : 
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
            <asp:ListItem Value="None" >None</asp:ListItem>
            <asp:ListItem Value="Day" Selected="true">Day</asp:ListItem>
            <asp:ListItem Value="DayWeek" >DayWeek</asp:ListItem>
            <asp:ListItem Value="DayWeekMonth" >DayWeekMonth</asp:ListItem>
        </asp:DropDownList>
    
        <p></p>
        <asp:Calendar ID="Calendar1" runat="server" OnSelectionChanged="Calendar1_SelectionChanged"></asp:Calendar>
    </div>
    </form>
</body>
</html>