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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace StructuredNavigationDemo
{
    /// <summary>
    /// ProfileFunction.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ProfileFunction : PageFunction<Employee>
    {
        public ProfileFunction()
        {
            InitializeComponent();
            
        }
        public ProfileFunction(string irum,string juso)
        {
            InitializeComponent();
            textIrum.Text = irum;
            textJuso.Text = juso;
            

        }
        

        private void btnYes_Click(object sender, RoutedEventArgs e)
        {
            Employee emp = new Employee();
            emp.YesOrNo = true;
            OnReturn(new ReturnEventArgs<Employee>(emp));
        }

        private void btnNo_Click(object sender, RoutedEventArgs e)
        {
            Employee emp = new Employee();
            emp.YesOrNo = false;
            OnReturn(new ReturnEventArgs<Employee>(emp));
        }
        
    }
    public class Employee
    {
        private bool yesOrNo;

        public bool YesOrNo
        {
            get { return yesOrNo; }
            set { yesOrNo = value; }
        }

        
    
    }
}
