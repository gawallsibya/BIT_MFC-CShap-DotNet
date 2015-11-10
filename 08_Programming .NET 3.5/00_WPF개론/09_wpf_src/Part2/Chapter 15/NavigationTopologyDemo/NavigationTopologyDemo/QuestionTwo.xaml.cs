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
    /// QuestionTwo.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class QuestionTwo :PageFunction<SurveyResult>
    {
        SurveyContext context;
        public QuestionTwo()
        {
            InitializeComponent();
            
        }
        public QuestionTwo(SurveyContext context)
        {
            InitializeComponent();
            this.context = context;
        }

        private void btnGoBack_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.GoBack();
        }

        private void btnGoNext_Click(object sender, RoutedEventArgs e)
        {
            context._SurveyResult.QuestionTwo = textResult.Text;
            QuestionThree questionThree = new QuestionThree(context);
            NavigationService.Navigate(questionThree);
            questionThree.Return += new ReturnEventHandler<SurveyResult>(questionThree_Return);
        }

        void questionThree_Return(object sender, ReturnEventArgs<SurveyResult> e)
        {
            OnReturn(new ReturnEventArgs<SurveyResult>(e.Result));
            //throw new NotImplementedException();

        }

        private void btnCancer_Click(object sender, RoutedEventArgs e)
        {
            context._SurveyResult.Cancered = true;
            OnReturn(new ReturnEventArgs<SurveyResult>(context._SurveyResult));
        }

        private void btnFinish_Click(object sender, RoutedEventArgs e)
        {
            context._SurveyResult.QuestionTwo = textResult.Text;
            OnReturn(new ReturnEventArgs<SurveyResult>(context._SurveyResult));
        }
    }
}
