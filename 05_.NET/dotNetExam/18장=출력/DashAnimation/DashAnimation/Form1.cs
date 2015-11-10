using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace DashAnimation
{
	public partial class Form1 : Form
	{
		float Offset = 0;
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.Black, 2);
			P.DashStyle = DashStyle.Dash;
			P.DashOffset = Offset;
			e.Graphics.DrawRectangle(P, 50, 10, 200, 150);
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			Offset--;
			if (Offset < 0) Offset = 3;
			Invalidate();
		}
	}
}
