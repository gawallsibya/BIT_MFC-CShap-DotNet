using System;
using System.Drawing;
using System.Windows.Forms;

class MDHForm : Form
{
	public static void Main()
	{
		MDHForm MyForm = new MDHForm();
		MyForm.Text = "MDH로 만든 폼";
		//*
		MyForm.Width = 400;
		MyForm.Height = 200;
		MyForm.FormBorderStyle = FormBorderStyle.FixedSingle;
		MyForm.MaximizeBox = false;
		MyForm.BackColor = System.Drawing.Color.Blue;
		MyForm.Opacity = 0.8;
		//*/
		Application.Run(MyForm);
	}
}
