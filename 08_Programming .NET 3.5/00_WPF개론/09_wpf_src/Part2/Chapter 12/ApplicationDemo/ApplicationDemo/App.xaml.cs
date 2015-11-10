using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Windows;

namespace ApplicationDemo
{
    /// <summary>
    /// App.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class App : Application
    {
        private void Application_Startup(object sender, StartupEventArgs e)
        {
            
            foreach (var str in e.Args)
            {
                MessageBox.Show(str);
            }
           
        }

        private void Application_Activated(object sender, EventArgs e)
        {
           
        }

        private void Application_Deactivated(object sender, EventArgs e)
        {

        }

        private void Application_SessionEnding(object sender, SessionEndingCancelEventArgs e)
        {

        }

        private void Application_Exit(object sender, ExitEventArgs e)
        {

        }
    }
}
