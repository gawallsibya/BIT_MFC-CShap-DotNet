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

namespace DataBindingBasicDemo
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void btnSetBinding_Click(object sender, RoutedEventArgs e)
        {
            Binding binding = new Binding();
            binding.Source = myStackPanel.Resources["PersonLee"] as Person;
            binding.Path = new PropertyPath("Name");
            myTextBox.SetBinding(TextBox.TextProperty, binding);

            //Person person = new Person();
            //person.Name = "강감찬";
            //person.Juso = "평안도";

            //Binding binding = new Binding();
            //binding.Source = person;
            //binding.Path = new PropertyPath("Name");
            //myTextBox.SetBinding(TextBox.TextProperty, binding);



        }
    }
}
