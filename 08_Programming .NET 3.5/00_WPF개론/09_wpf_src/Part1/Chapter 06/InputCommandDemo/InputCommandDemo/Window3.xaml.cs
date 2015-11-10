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
    /// <summary>
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(Window3_Loaded);
        }

        void Window3_Loaded(object sender, RoutedEventArgs e)
        {
           
            MouseGesture runCmdMouseGesture = new MouseGesture();
            runCmdMouseGesture.MouseAction = MouseAction.LeftClick;
            runCmdMouseGesture.Modifiers = ModifierKeys.Control;

            MouseBinding runCmdMouseBinding = new MouseBinding();
            runCmdMouseBinding.Gesture = runCmdMouseGesture;
            runCmdMouseBinding.Command = MyCommands.Run; 
            myCanvas.InputBindings.Add(runCmdMouseBinding);
        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            this.Close();
        }
    }
}
