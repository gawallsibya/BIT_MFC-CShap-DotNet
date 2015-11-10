using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace PenDash
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Pen P = new Pen(Color.Black, 3);

			// 대시 스타일 테스트
			P.DashStyle = DashStyle.Solid;
			e.Graphics.DrawLine(P, 10, 10, 200, 10);
			P.DashStyle = DashStyle.Dot;
			e.Graphics.DrawLine(P, 10, 30, 200, 30);
			P.DashStyle = DashStyle.Dash;
			e.Graphics.DrawLine(P, 10, 50, 200, 50);
			P.DashStyle = DashStyle.DashDot;
			e.Graphics.DrawLine(P, 10, 70, 200, 70);
			P.DashStyle = DashStyle.DashDotDot;
			e.Graphics.DrawLine(P, 10, 90, 200, 90);

			// 대시와 선의 굵기 테스트
			P.DashStyle = DashStyle.Dash;
			for (int w = 1; w < 10; w += 2)
			{
				P.Width = w;
				e.Graphics.DrawLine(P, 10, 120 + w * 10, 200, 120 + w * 10);
			}
		}
	}
}
