using System;
using System.Windows;
using System.Windows.Data;
using System.Data;
using System.Xml;
using System.Configuration;

namespace PhotoCooperative
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>

    public partial class App : System.Windows.Application
    {
        void AppStartup(object sender, StartupEventArgs args)
        {
            Window1 theWindow = new Window1();
            theWindow.Show();

            theWindow.Photos = (PhotoList)(this.Resources["Photos"] as ObjectDataProvider).Data;
            theWindow.Photos.Path = "..\\..\\Photos";

            theWindow.ShoppingCart = (PrintList)(this.Resources["ShoppingCart"] as ObjectDataProvider).Data;
        }

    }
}