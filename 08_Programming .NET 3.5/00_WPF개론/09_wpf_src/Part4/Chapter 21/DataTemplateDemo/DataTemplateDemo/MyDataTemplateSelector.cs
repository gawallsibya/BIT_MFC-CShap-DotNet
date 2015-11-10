using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace DataTemplateDemo
{
    public class MyDataTemplateSelector : DataTemplateSelector
    {
        public override DataTemplate SelectTemplate(object item,
                                                      DependencyObject container)
        {
            Person person = item as Person;
            if (person.Irum == "호나우두")
            {
                return (DataTemplate) 
                (container as FrameworkElement).FindResource("youPersonTemplate");
               
            }
            else
            {
                 return (DataTemplate) 
                (container as FrameworkElement).FindResource("myPersonTemplate");
            }
        }
    }

}
