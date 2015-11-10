using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace BrushOrigin
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Image I = Image.FromFile("인형.jpg");
			TextureBrush B = new TextureBrush(I);
			B.Transform = new Matrix(1, 0, 0, 1, 50, 50);
			e.Graphics.FillRectangle(B, 50, 50,
				ClientRectangle.Right, ClientRectangle.Bottom);
		}
	}
}
