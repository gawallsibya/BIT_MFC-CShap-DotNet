// �����ڷ�: Nikola Paljetak
// ������: �ڰ���(HOONS)
// ��� Ŀ�´�Ƽ : HOONS��� - http://www.hoonsbara.com

using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace NikeSoftChat
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new ChatForm());
        }
    }
}