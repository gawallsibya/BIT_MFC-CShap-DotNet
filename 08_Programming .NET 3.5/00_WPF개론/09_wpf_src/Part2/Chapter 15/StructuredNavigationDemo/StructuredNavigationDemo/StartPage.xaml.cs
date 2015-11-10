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
    /// StartPage.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class StartPage : Page
    {
        public StartPage()
        {
            InitializeComponent();
        }

        private void btnConfirm_Click(object sender, RoutedEventArgs e)
        {
            string irum = textName.Text;
            string juso = textAddress.Text;
            ProfileFunction pf = new ProfileFunction(irum,juso);
            pf.Return += new ReturnEventHandler<Employee>(pf_Return);
            NavigationService.Navigate(pf);
        }

        void pf_Return(object sender, ReturnEventArgs<Employee> e)
        {
            //throw new NotImplementedException();
            if (e.Result.YesOrNo)
            {
                textYesOrNo.Text = "Yes";
            }
            else
            {
                textYesOrNo.Text = "No";
            
            }
        }
    }
}
