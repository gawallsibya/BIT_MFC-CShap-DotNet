using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace AlphaColor
{
	public partial class Form1 : Form
	{
		int Alpha = 128;

		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			e.Graphics.FillEllipse(Brushes.Blue, 10, 10, 150, 100);
			SolidBrush S = new SolidBrush(Color.FromArgb(Alpha, 255, 0, 0));
			e.Graphics.FillRectangle(S, 50, 50, 150, 100);
			e.Graphics.DrawString("위:투명도 증가, 아래:투명도 감소",
				Font, Brushes.Black, 10, 160);
		}

		private void Form1_KeyDown(object sender, KeyEventArgs e)
		{
			switch (e.KeyCode)
			{
				case Keys.Up:
					Alpha = Math.Max(0, Alpha - 25);
					Invalidate();
					break;
				case Keys.Down:
					Alpha = Math.Min(255, Alpha + 25);
					Invalidate();
					break;
			}
		}
	}
}
