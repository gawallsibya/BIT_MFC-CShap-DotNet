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

namespace MultimediaDemo
{
    /// <summary>
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
       
        public Window2()
        {
            InitializeComponent();
            
        }

     

        private void btnPlay_Click(object sender, RoutedEventArgs e)
        {
            MediaPlayer player;
            player = new MediaPlayer();

            player.Open(new Uri(@"Bear.wmv", UriKind.Relative));

            VideoDrawing aVideoDrawing = new VideoDrawing();


            aVideoDrawing.Rect = new Rect(0, 0, 100, 100);

            aVideoDrawing.Player = player;
            DrawingBrush db = new DrawingBrush(aVideoDrawing);
            rectangle1.Fill = db;
            //rectangle2.Fill = db;
            player.Play();
        }
        
    }
}
