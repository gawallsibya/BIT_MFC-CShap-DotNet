//------------------------------------------------
// CraftTheToolbar.cs (c) 2006 by Charles Petzold
//------------------------------------------------
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Petzold.CraftTheToolbar
{
    public class CraftTheToolbar : Window
    {
        [STAThread]
        public static void Main()
        {
            Application app = new Application();
            app.Run(new CraftTheToolbar());
        }
        public CraftTheToolbar()
        {
            Title = "Craft the Toolbar";

            RoutedUICommand[] comm =
                {
                    ApplicationCommands.New, ApplicationCommands.Open,
                    ApplicationCommands.Save, ApplicationCommands.Print,
                    ApplicationCommands.Cut, ApplicationCommands.Copy,
                    ApplicationCommands.Paste, ApplicationCommands.Delete
                };

            string[] strImages = 
                { 
                    "NewDocumentHS.png", "openHS.png", "saveHS.png", 
                    "PrintHS.png", "CutHS.png", "CopyHS.png", 
                    "PasteHS.png", "DeleteHS.png"
                };

            // Create DockPanel as content of window.
            DockPanel dock = new DockPanel();
            dock.LastChildFill = false;
            Content = dock;

            // Create Toolbar docked at top of window.
            ToolBar toolbar = new ToolBar();
            dock.Children.Add(toolbar);
            DockPanel.SetDock(toolbar, Dock.Top);

            RichTextBox txtbox = new RichTextBox();
            dock.Children.Add(txtbox);

            txtbox.Focus();

            // Create the Toolbar buttons.
            for (int i = 0; i < 8; i++)
            {
                if (i == 4)
                    toolbar.Items.Add(new Separator());

                // Create the Button.
                Button btn = new Button();
                btn.Command = comm[i];
                toolbar.Items.Add(btn);

                // Create an Image as content of the Button.
                Image img = new Image();
                img.Source = new BitmapImage(
                    new Uri("pack://application:,,/Images/" + strImages[i]));
                img.Stretch = Stretch.None;
                btn.Content = img;

                //StackPanel stack = new StackPanel();
                //stack.Orientation = Orientation.Horizontal;
                //btn.Content = stack;

                //TextBlock txtblk = new TextBlock();
                //txtblk.Text = comm[i].Text;

                //stack.Children.Add(img);
                //stack.Children.Add(txtblk);

                // Create a ToolTip based on the UICommand text.
                ToolTip tip = new ToolTip();
                tip.Content = comm[i].Text;
                btn.ToolTip = tip;

                // 이벤트 핸들러를 RoutedUICommand 객체와 연결하기 위해 커맨드 바인딩 컬렉션에 커맨트 객체를 추가해준다. 
                CommandBindings.Add(
                    new CommandBinding(comm[i], ToolBarButtonOnClick));
            }
        }
        // Do-nothing command handler for button.
        void ToolBarButtonOnClick(object sender, ExecutedRoutedEventArgs args)
        {
            RoutedUICommand comm = args.Command as RoutedUICommand;
            MessageBox.Show(comm.Name + 
                            " command not yet implemented", Title);
        }
    }
}
