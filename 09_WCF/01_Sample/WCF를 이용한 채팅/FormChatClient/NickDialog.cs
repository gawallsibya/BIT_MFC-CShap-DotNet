// �����ڷ�: Nikola Paljetak
// ������: �ڰ���(HOONS)
// ��� Ŀ�´�Ƽ : HOONS��� - http://www.hoonsbara.com

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace NikeSoftChat
{
    public partial class NickDialog : Form
    {
        public NickDialog()
        {
            InitializeComponent();
        }

        private void txtNick_TextChanged(object sender, EventArgs e)
        {
            btnOK.Enabled = txtNick.Text.Length > 0 ? true : false;
        }
    }
}