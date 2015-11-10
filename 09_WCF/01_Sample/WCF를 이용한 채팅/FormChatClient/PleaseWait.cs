// Âü°íÀÚ·á: Nikola Paljetak
// ¸¸µçÀÌ: ¹Ú°æÈÆ(HOONS)
// ´å³Ý Ä¿¹Â´ÏÆ¼ : HOONS´å³Ý - http://www.hoonsbara.com

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace NikeSoftChat
{
    public partial class PleaseWaitDialog : Form
    {
        public PleaseWaitDialog()
        {
            InitializeComponent();
        }

        public void ShowError(string errMessage)
        {
            this.lblErrorMessage.Text = errMessage;
            this.pnlError.BringToFront();
            this.Text = "Connection error";
            pnlConnecting.Visible = false;
            pnlError.Visible = true;
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}