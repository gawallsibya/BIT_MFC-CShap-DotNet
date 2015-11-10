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

namespace RoutedEventDemo
{
    class Animal:UIElement
    {
        public static readonly RoutedEvent CryEvent =
        EventManager.RegisterRoutedEvent("Cry", RoutingStrategy.Bubble, typeof(RoutedEventHandler),typeof(Animal));

        public event RoutedEventHandler Cry
        {
            add { AddHandler(CryEvent, value); }
            remove { RemoveHandler(CryEvent, value); }
        }

    }
}
