<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

    protected void Calendar1_DayRender(object sender, DayRenderEventArgs e)
    {
        CalendarDay d = e.Day;
        TableCell c = e.Cell;

        if (d.IsOtherMonth)
        {
            c.Controls.Clear();
        }
        else
        {
            string message = GetSchedule(d.Date.Month, d.Date.Day);
            c.Controls.Add(new LiteralControl("<br>" + message));
        }
    }

    string GetSchedule(int month, int day)
    {
        string schedule = "";
        
        if (month == 10 && day == 3)    // 10�� 3��
        {
            schedule = "<a href='http://www.naver.com'>��õ��</a>";    
        }
        else if (month == 10 && day == 10)  // 10�� 10��
        {
            schedule = "���ױ����ǳ�";
        }
        else if ( month == 11 && day == 17 ) // 11�� 17�� 
        {
            schedule = "���������ǳ�";
        }
        else if (month == 12 && day == 25) // 12�� 25�� 
        {
            schedule = "ũ��������";
        }

        return schedule;
    }    
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>���� ����</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h3>Calendar�� DayRender�̺�Ʈ�� ����� ����</h3>
        
        <asp:Calendar ID="Calendar1" runat="server" OnDayRender="Calendar1_DayRender" ShowGridLines="true" Width="500px" TitleStyle-BackColor="Gainsboro" TitleStyle-Font-Size="12px" TitleStyle-Font-Bold="true" DayStyle-VerticalAlign="Top" DayStyle-Height="50px" DayStyle-Width="14%" SelectedDayStyle-BackColor="Navy" VisibleDate="10/1/2006"></asp:Calendar>
    </div>
    </form>
</body>
</html>