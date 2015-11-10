using System;
using System.Runtime.InteropServices;   // dllimport 어트리뷰트 정의됨
using ADDMYCALCOMLib;
namespace test
{

    class Program
    {
        [DllImport("User32.dll")] //Win32 : User32.dll참조
        public static extern int MessageBox(int hwnd, string lpText,
                    string lpCation, int uType);
        [DllImport("xyz.dll")]
        public static extern int Add(int num1, int num2);

        static void Main(string[] args)
        {
        //    Console.WriteLine("{0}\n", Add(10, 20));
            //MessageBox(0, "Win32 MessageBox호출", "DllImport사용", 3);

            CalClass cal = new CalClass();
            ICal ical = cal;
            //Event 처리 ==============================================
            ICalEvent_Event icalEvent = (ICalEvent_Event)cal;
            icalEvent.ResltNumber += new ICalEvent_ResltNumberEventHandler(foo);
            icalEvent.Test += new ICalEvent_TestEventHandler(woo);
            //=======================================================
            ical.StringTest("AAAAAAAAAAAAA");
            ical.Add(10, 20);
            int num = ical.Result;
            Console.WriteLine("{0}\n", num);
        }
        // raw event ================================================
        public static void woo(string str)
        {           
            Console.WriteLine("문자열 = {0}\n", str);
        }
        public static void foo( int num)
        {
            Console.WriteLine("이벤트 수신 = {0}\n", num);
        }
    }
}
