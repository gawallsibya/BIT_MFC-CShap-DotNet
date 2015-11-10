using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace Texture
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Image I = Image.FromFile("클로버.jpg");
			TextureBrush B = new TextureBrush(I);
			//TextureBrush B = new TextureBrush(I, WrapMode.TileFlipX);
			//TextureBrush B = new TextureBrush(I, WrapMode.TileFlipY); 
			e.Graphics.FillRectangle(B, ClientRectangle);
		}
	}
}
