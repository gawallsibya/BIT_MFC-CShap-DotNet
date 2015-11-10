using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DrawString
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			e.Graphics.DrawString("한 줄짜리 문자열이며 DrawString으로 출력했습니다.",
				Font, Brushes.Black, 10, 10);

			Rectangle R = new Rectangle(10, 50, 100, 100);
			string str = "청산은 나를 보고 말없이 살라 하고. 창공은 나를 보고 티없이 살라 하네";
			e.Graphics.DrawRectangle(Pens.Blue, R);
			e.Graphics.DrawString(str, Font, Brushes.Red, R);
		}
	}
}
