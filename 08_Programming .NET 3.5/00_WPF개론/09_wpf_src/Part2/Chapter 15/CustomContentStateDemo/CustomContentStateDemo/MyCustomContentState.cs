using System;
using System.Collections.Generic;
using System.Text;

namespace CustomContentStateDemo
{
    using System;
    using System.Windows.Controls;
    using System.Windows.Navigation;
    [Serializable]
    public class MyCustomContentState : CustomContentState
    {
        TextBox irum;
        TextBox juso;
        string strIrum;
        string strJuso;

        public MyCustomContentState( TextBox irum,TextBox juso)
        {
            this.irum=irum;
            this.juso=juso;
            strIrum = irum.Text;
            strJuso = juso.Text;
        }

        public override string JournalEntryName
        {
            get
            {
                return "Journal Entry " + this.irum.Text;
            }
        }

        public override void Replay(NavigationService navigationService, NavigationMode mode)
        {
            irum.Text = strIrum;
            juso.Text = strJuso;
        }
    }
}
