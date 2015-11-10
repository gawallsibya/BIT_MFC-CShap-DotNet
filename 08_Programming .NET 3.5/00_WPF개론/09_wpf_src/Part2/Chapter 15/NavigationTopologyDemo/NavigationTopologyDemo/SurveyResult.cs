using System;
using System.Collections.Generic;
using System.Text;

namespace NavigationTopologyDemo
{
    public class SurveyResult
    {
        private string questionOne;

        public string QuestionOne
        {
            get { return questionOne; }
            set { questionOne = value; }
        }
        private string questionTwo;

        public string QuestionTwo
        {
            get { return questionTwo; }
            set { questionTwo = value; }
        }
        private string questionThree;

        public string QuestionThree
        {
            get { return questionThree; }
            set { questionThree = value; }
        }
        private bool cancered;

        public bool Cancered
        {
            get { return cancered; }
            set { cancered = value; }
        }
    }
}
