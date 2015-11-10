using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Text;

namespace AntiAlias
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

			e.Graphics.TextRenderingHint = TextRenderingHint.SystemDefault;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 10);

			e.Graphics.TextRenderingHint = TextRenderingHint.AntiAlias;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 40);
			e.Graphics.TextRenderingHint = TextRenderingHint.AntiAliasGridFit;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 70);
			e.Graphics.TextRenderingHint = TextRenderingHint.ClearTypeGridFit;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 100);
			e.Graphics.TextRenderingHint = TextRenderingHint.SingleBitPerPixel;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 130);
			e.Graphics.TextRenderingHint = TextRenderingHint.SingleBitPerPixelGridFit;
			e.Graphics.DrawString("대한민국", F1, Brushes.Black, 10, 160);
		}
	}
}
