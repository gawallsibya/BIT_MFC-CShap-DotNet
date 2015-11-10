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
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        Animal animal = new Animal();
        public Window3()
        {
            InitializeComponent(); 
            animal.Cry += new RoutedEventHandler(animal_Cry);
        }

        void animal_Cry(object sender, RoutedEventArgs e)
        {
            //throw new NotImplementedException();
            MessageBox.Show("Raised CryEvent");
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            animal.RaiseEvent(new RoutedEventArgs(Animal.CryEvent));
            //clickMeButton.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        }

        private void clickMeButton_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Clik Me");
        }

        
    }
}
