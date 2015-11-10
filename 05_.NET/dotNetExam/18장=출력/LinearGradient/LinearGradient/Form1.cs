using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace LinearGradient
{
	public partial class Form1 : Form
	{
		private float angle = 0f;

		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			LinearGradientBrush B1 = new LinearGradientBrush(new Point(0, 0),
				new Point(100, 100), Color.Blue, Color.Yellow);
			e.Graphics.FillRectangle(B1, 0, 0, 300, 150);

			LinearGradientBrush B2 = new LinearGradientBrush(new Rectangle(0, 0, 100, 100),
				Color.White, Color.Black, angle);
			e.Graphics.FillRectangle(B2, 0, 200, 300, 150);
		}

		private void Form1_KeyDown(object sender, KeyEventArgs e)
		{
			switch (e.KeyCode)
			{
				case Keys.Up:
					angle += 5f;
					break;
				case Keys.Down:
					angle -= 5f;
					break;
			}
			Invalidate();
		}
	}
}
