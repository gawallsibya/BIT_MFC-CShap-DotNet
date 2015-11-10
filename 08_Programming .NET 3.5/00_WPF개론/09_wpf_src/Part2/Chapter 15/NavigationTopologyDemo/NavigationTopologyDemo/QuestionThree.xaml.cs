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
    /// PageThree.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class QuestionThree : PageFunction<SurveyResult>
    {
        SurveyContext context;
        public QuestionThree()
        {
            InitializeComponent();
        }

        public QuestionThree(SurveyContext context)
        {
            InitializeComponent();
            this.context = context;
        }

        private void btnGoBack_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.GoBack();
        }

        private void btnCancer_Click(object sender, RoutedEventArgs e)
        {
            context._SurveyResult.Cancered = true;
            OnReturn(new ReturnEventArgs<SurveyResult>(context._SurveyResult));
        }

        private void btnFinish_Click(object sender, RoutedEventArgs e)
        {
            context._SurveyResult.QuestionThree = textResult.Text;
            OnReturn(new ReturnEventArgs<SurveyResult>(context._SurveyResult));
        }

        
        
    }
}
