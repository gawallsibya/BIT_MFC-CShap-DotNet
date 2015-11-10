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

namespace NavigationTopologyDemo
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

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            SurveyContext sc = new SurveyContext();
            SurveyResult result = new SurveyResult();
            sc._SurveyResult = result;
           

            SurveyController controller = new SurveyController(sc);
            controller.Return += new ReturnEventHandler<SurveyResult>(controller_Return);
            NavigationService.Navigate(controller);
        
        }

        void controller_Return(object sender, ReturnEventArgs<SurveyResult> e)
        {
            SurveyResult result = e.Result;
            lblAnsQ1.Content = result.QuestionOne;
            lblAnsQ2.Content = result.QuestionTwo;
            lblAnsQ3.Content = result.QuestionThree;
        }

        private void btnStartSurvey_Click(object sender, RoutedEventArgs e)
        {
            SurveyContext sc = new SurveyContext();
            SurveyResult result = new SurveyResult();
            sc._SurveyResult = result;
         

            SurveyController controller = new SurveyController(sc);
            controller.Return += new ReturnEventHandler<SurveyResult>(controller_Return);
            NavigationService.Navigate(controller);
        }
    }
}
