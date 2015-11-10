using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace PenCap
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.Black, 9);

			// 시작, 끝 캡 테스트
			P.StartCap = P.EndCap = LineCap.Flat;
			e.Graphics.DrawLine(P, 10, 20, 200, 20);
			P.StartCap = P.EndCap = LineCap.Round;
			e.Graphics.DrawLine(P, 10, 40, 200, 40);
			P.StartCap = P.EndCap = LineCap.Square;
			e.Graphics.DrawLine(P, 10, 60, 200, 60);
			P.StartCap = P.EndCap = LineCap.Triangle;
			e.Graphics.DrawLine(P, 10, 80, 200, 80);
			P.StartCap = P.EndCap = LineCap.RoundAnchor;
			e.Graphics.DrawLine(P, 10, 100, 200, 100);
			P.StartCap = P.EndCap = LineCap.SquareAnchor;
			e.Graphics.DrawLine(P, 10, 120, 200, 120);
			P.StartCap = P.EndCap = LineCap.ArrowAnchor;
			e.Graphics.DrawLine(P, 10, 140, 200, 140);
			P.StartCap = P.EndCap = LineCap.DiamondAnchor;
			e.Graphics.DrawLine(P, 10, 160, 200, 160);

			// 대시 캡 테스트
			P.StartCap = P.EndCap = LineCap.Flat;
			P.Width = 15;
			P.DashStyle = DashStyle.Dash;
			P.DashCap = DashCap.Flat;
			e.Graphics.DrawLine(P, 10, 200, 200, 200);
			P.DashCap = DashCap.Round;
			e.Graphics.DrawLine(P, 10, 220, 200, 220);
			P.DashCap = DashCap.Triangle;
			e.Graphics.DrawLine(P, 10, 240, 200, 240);

		}
	}
}
