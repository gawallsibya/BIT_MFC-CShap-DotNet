using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace PenLineJoin
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.Black, 15);
			P.LineJoin = LineJoin.Miter;
			e.Graphics.DrawRectangle(P, 10, 10, 80, 80);
			P.LineJoin = LineJoin.MiterClipped;
			e.Graphics.DrawRectangle(P, 120, 10, 80, 80);
			P.LineJoin = LineJoin.Bevel;
			e.Graphics.DrawRectangle(P, 10, 120, 80, 80);
			P.LineJoin = LineJoin.Round;
			e.Graphics.DrawRectangle(P, 120, 120, 80, 80);
		}
	}
}
