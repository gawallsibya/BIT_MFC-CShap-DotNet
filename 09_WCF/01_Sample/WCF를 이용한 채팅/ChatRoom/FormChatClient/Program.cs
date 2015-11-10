// 참고자료: Nikola Paljetak
// 만든이: 박경훈(HOONS)
// 닷넷 커뮤니티 : HOONS닷넷 - http://www.hoonsbara.com

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