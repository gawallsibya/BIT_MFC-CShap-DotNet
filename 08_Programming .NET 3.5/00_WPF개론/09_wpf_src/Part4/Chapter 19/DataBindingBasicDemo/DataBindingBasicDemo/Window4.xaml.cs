using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Data;

namespace DataBindingBasicDemo
{
    /// <summary>
    /// Window4.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window4 : Window
    {
        MyDataSet.EmployeeDataTable mycontext;
        BindingListCollectionView bv; 
        public Window4()
        {
            InitializeComponent();
            mycontext=MakeDataSource();
            bv= new BindingListCollectionView(mycontext.DefaultView);
            myCanvas.DataContext = bv;
        }

        
        private MyDataSet.EmployeeDataTable MakeDataSource()
        {
            MyDataSet.EmployeeDataTable myTable = new MyDataSet.EmployeeDataTable();

            myTable.AddEmployeeRow("A12345","이순신","한려 수도 가까운 바다",false,DateTime.Parse("1500-09-07"));
            myTable.AddEmployeeRow("K43214", "강감찬", "평나도 강가 ", false, DateTime.Parse("1100-04-07"));
            myTable.AddEmployeeRow("J09537", "홍길동", "산속 어디 아름다운곳", true, DateTime.Parse("1407-02-23"));

            return myTable;
        }

        private void btnPrevious_Click(object sender, RoutedEventArgs e)
        {
            bv.MoveCurrentToPrevious();
        }

        private void btnNext_Click(object sender, RoutedEventArgs e)
        {
            bv.MoveCurrentToNext();
        }

        
        

        
    }
}
