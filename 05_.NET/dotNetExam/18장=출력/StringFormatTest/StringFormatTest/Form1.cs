using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Text;

namespace StringFormatTest
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			StringFormat F = new StringFormat();

			// 정렬 테스트
			F.Alignment = StringAlignment.Near;
			e.Graphics.DrawString("왼쪽 정렬", Font, Brushes.Black, 100, 10, F);
			F.Alignment = StringAlignment.Center;
			e.Graphics.DrawString("중앙 정렬", Font, Brushes.Black, 100, 30, F);
			F.Alignment = StringAlignment.Far;
			e.Graphics.DrawString("오른쪽 정렬", Font, Brushes.Black, 100, 50, F);

			// 핫키 테스트
			F.Alignment = StringAlignment.Near;
			F.HotkeyPrefix = HotkeyPrefix.Hide;
			e.Graphics.DrawString("&Hotkey", Font, Brushes.Black, 10, 100, F);
			F.HotkeyPrefix = HotkeyPrefix.Show;
			e.Graphics.DrawString("&Hotkey", Font, Brushes.Black, 10, 120, F);
			F.HotkeyPrefix = HotkeyPrefix.None;
			e.Graphics.DrawString("&Hotkey", Font, Brushes.Black, 10, 140, F);

			// 플래그 테스트
			F.FormatFlags |= StringFormatFlags.DirectionVertical;
			e.Graphics.DrawString("우리나라", Font, Brushes.Black, 150, 100, F);
		}
	}
}
