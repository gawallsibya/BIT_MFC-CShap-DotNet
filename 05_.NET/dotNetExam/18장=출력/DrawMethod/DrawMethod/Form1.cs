using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace DrawMethod
{
	public partial class Form1 : Form
	{
		private float tension = 0;

		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			Graphics G = e.Graphics;

			/* 직선 그리기
			G.DrawLine(Pens.Black, 12, 34, 56, 78);
			G.DrawLine(Pens.Black, new Point(12, 34), new Point(56, 78));
			//*/

			/* 오각형 그리기
			Point[] Penta = { new Point(112, 0), new Point(0, 83), new Point(45, 215), 
				new Point(182, 215), new Point(223, 83), new Point(112, 0) };
			G.DrawLines(Pens.Black, Penta);
			//*/

			/* 사각형, 원 그리기
			Pen P = new Pen(Color.Blue, 5);
			Brush B = Brushes.Red;
			G.DrawEllipse(P, 10, 10, 100, 100);
			G.DrawRectangle(P, 120, 10, 100, 100);
			G.FillEllipse(B, 10, 120, 100, 100);
			G.FillRectangle(B, 120, 120, 100, 100);
			//*/

			/* 다각형 그리기
			Point[] Korea = { 
				new Point(292,6),new Point(331,45),new Point(307,45),new Point(269,77),
				new Point(274,111),new Point(251,116),new Point(207,149),new Point(165,155),
				new Point(161,190),new Point(201,206),new Point(239,270),new Point(258,287),
				new Point(257,306),new Point(249,313),new Point(251,335),new Point(263,333),
				new Point(252,364),new Point(231,380),new Point(203,378),new Point(201,392),
				new Point(181,391),new Point(157,389),new Point(143,404),new Point(117,402),
				new Point(108,416),new Point(95,403),new Point(108,393),new Point(96,378),
				new Point(121,341),new Point(109,302),new Point(96,303),new Point(95,292),
				new Point(114,285),new Point(132,292),new Point(121,267),new Point(114,243),
				new Point(74,231),new Point(72,251),new Point(26,231),new Point(70,205),
				new Point(51,198),new Point(71,166),new Point(13,142),new Point(90,103),
				new Point(132,73),new Point(151,56),new Point(161,71),new Point(202,79),
				new Point(211,66),new Point(206,51),new Point(241,49),new Point(266,30),
				new Point(282,26),new Point(283,7)
			};

			G.FillPolygon(Brushes.LightGreen, Korea);
			G.DrawPolygon(new Pen(Color.Blue, 3), Korea);
			//*/

			/* 채우기 모드
			Point[] Star = { new Point(30,40), new Point(240,150), new Point(40,190),
				new Point(140,20), new Point(180,210) };
			G.FillPolygon(Brushes.Red, Star, FillMode.Alternate);
			//G.FillPolygon(Brushes.Red, Star, FillMode.Winding);
			//*/

			/* 호, 파이 그리기
			G.DrawArc(Pens.Black, new Rectangle(10, 10, 100, 100), 0, -60);
			G.DrawPie(Pens.Black, new Rectangle(120, 10, 100, 100), 0, -60);
			G.FillPie(Brushes.Blue, new Rectangle(120, 120, 100, 100), 0, -60);
			//*/

			/* 베지어 곡선
			G.DrawBezier(Pens.Black, new Point(10, 10), new Point(150, 30), 
				new Point(30, 150), new Point(200, 200));
			//*/

			//* 카디널 곡선
			Point[] pts = { new Point(10, 80), new Point(100, 10), 
				new Point(80, 200), new Point(200, 150) };
			G.DrawCurve(Pens.Black, pts, tension);
			G.DrawString("장력 : " + tension, Font, Brushes.Black, 0, 220);
			//*/
		}

		private void Form1_KeyDown(object sender, KeyEventArgs e)
		{
			switch (e.KeyCode)
			{
				case Keys.Up:
					tension += 0.1f;
					Invalidate();
					break;
				case Keys.Down:
					tension -= 0.1f;
					Invalidate();
					break;
			}
		}
	}
}
