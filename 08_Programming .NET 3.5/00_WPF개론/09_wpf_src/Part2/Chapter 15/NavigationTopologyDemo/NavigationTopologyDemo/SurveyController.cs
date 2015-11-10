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
    class SurveyController : PageFunction<SurveyResult>
    {
        SurveyContext context;
        public SurveyController()
        { 
        
        }
      
        public SurveyController(SurveyContext context)
        {
            this.context = context;
                        
           
        }
        protected override void Start()
        {
            base.Start();
            this.KeepAlive = true;
            QuestionOne questionOne = new QuestionOne(context);
            questionOne.Return += new ReturnEventHandler<SurveyResult>(questionOne_Return);
            this.NavigationService.Navigate(questionOne);
            

        }

        void questionOne_Return(object sender, ReturnEventArgs<SurveyResult> e)
        {
          OnReturn(new ReturnEventArgs<SurveyResult>(e.Result));
        }
    }
}
