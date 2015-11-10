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
    public class SurveyContext
    {
        SurveyResult mSurveyResult;
    
        //
        // 필요한 context 정보 입력 하세요
        //
     
        public SurveyResult _SurveyResult
        {
            get { return mSurveyResult; }
            set { mSurveyResult = value; }
        }
    }
}
