using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace EnumFont
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
			SetStyle(ControlStyles.ResizeRedraw, true);
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			FontFamily[] Fms = FontFamily.Families;
			int x = 10, y = 10;

			foreach (FontFamily Fm in Fms)
			{
				try
				{
					Font F = new Font(Fm, 15);
					e.Graphics.DrawString(Fm.Name, F, Brushes.Black, x, y);
					y += 20;
					if (y > ClientSize.Height - 20)
					{
						x += 200;
						y = 10;
					}
				}
				catch
				{
				}
			}
		}
	}
}
