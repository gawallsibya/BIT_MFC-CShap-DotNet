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
namespace AttachedPropertyDemo
{
    public class NameFactory : DependencyObject
    {
        public static readonly DependencyProperty CallNameProperty
            = DependencyProperty.RegisterAttached("CallName", typeof(string),
                                       typeof(NameFactory), new PropertyMetadata(""));

        public static void SetCallName(UIElement element, string value)
        {
            element.SetValue(CallNameProperty, value);
        }

        public static string GetCallName(UIElement element)
        {
            return (string)element.GetValue(CallNameProperty);
        }

    }

}
