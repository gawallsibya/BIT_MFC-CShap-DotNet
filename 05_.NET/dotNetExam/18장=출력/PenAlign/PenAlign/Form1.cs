using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace PenAlign
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.DodgerBlue, 15);
			P.Alignment = PenAlignment.Center;
			e.Graphics.DrawRectangle(P, 10, 10, 80, 80);
			P.Alignment = PenAlignment.Inset;
			e.Graphics.DrawRectangle(P, 120, 10, 80, 80);
			P.Alignment = PenAlignment.Outset;
			e.Graphics.DrawRectangle(P, 10, 120, 80, 80);
			P.Alignment = PenAlignment.Left;
			e.Graphics.DrawRectangle(P, 120, 120, 80, 80);

			e.Graphics.DrawRectangle(Pens.Black, 10, 10, 80, 80);
			e.Graphics.DrawRectangle(Pens.Black, 120, 10, 80, 80);
			e.Graphics.DrawRectangle(Pens.Black, 10, 120, 80, 80);
			e.Graphics.DrawRectangle(Pens.Black, 120, 120, 80, 80);
		}
	}
}
