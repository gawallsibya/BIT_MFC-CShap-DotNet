using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace HatchBrushTest
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			int x, y;
			HatchStyle H = (HatchStyle)0;
			for (y = 0; ; y++)
			{
				for (x = 0; x < 8; x++)
				{
					HatchBrush B = new HatchBrush(H, Color.White, Color.Black);
					e.Graphics.FillRectangle(B, x * 70, y * 70, 60, 60);
					H++;
					if (H > (HatchStyle)52) break;
				}
				if (H > (HatchStyle)52) break;
			}
		}
	}
}
