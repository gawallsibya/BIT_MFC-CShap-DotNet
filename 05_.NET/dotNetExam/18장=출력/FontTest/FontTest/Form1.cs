using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FontTest
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Font F1 = new Font("궁서", 20);
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 10);

			Font F2 = new Font("궁서", 20, FontStyle.Italic | FontStyle.Underline);
			e.Graphics.DrawString("대한민국", F2, Brushes.Black, 10, 40);

			FontFamily Fm = new FontFamily("궁서");
			Font F3 = new Font(Fm, 20);
			e.Graphics.DrawString("대한민국", F3, Brushes.Black, 10, 70);
		}
	}
}
