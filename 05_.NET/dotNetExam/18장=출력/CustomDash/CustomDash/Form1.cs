using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace CustomDash
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.Black, 5);
			P.DashStyle = DashStyle.Custom;
			P.DashPattern = new float[] { 3, 4, 5, 6, 7, 8 };
			e.Graphics.DrawLine(P, 10, 10, 250, 10);

			for (int o = 0; o < 10; o++)
			{
				P.DashOffset = o;
				e.Graphics.DrawLine(P, 10, 50 + o * 20, 250, 50 + o * 20);
			}
		}
	}
}
