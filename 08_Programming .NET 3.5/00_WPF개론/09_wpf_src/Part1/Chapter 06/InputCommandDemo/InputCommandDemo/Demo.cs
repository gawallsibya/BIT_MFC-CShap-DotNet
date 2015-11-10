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
using System.Windows.Shapes;

namespace InputCommandDemo
{
    public class MyCommands
    {
        public static RoutedCommand Run = new RoutedCommand();
        public static RoutedCommand Pause = new RoutedCommand();
        public static RoutedCommand Stop = new RoutedCommand();

    }
}
