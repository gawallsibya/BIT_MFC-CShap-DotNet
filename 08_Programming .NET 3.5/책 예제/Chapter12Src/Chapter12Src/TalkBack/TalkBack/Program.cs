using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TalkBack
{
    class Program
    {
        static void Main(string[] args)
        {
            // print an instruction
            String key = DateTime.Now.GetHashCode().ToString();

            Console.WriteLine("Enter the following key to continue: " + key);

            String input = Console.ReadLine();

            if (key.Equals(input))
            {
                Console.WriteLine("We have a match: " + key + " = " + input);

            }
            else
            {
                Console.WriteLine("Oops! " + key + " is not the same as " + input);

            }

            // leave something on the screen and wait for input to exit
            Console.WriteLine("");
            Console.WriteLine("Press Enter to exit...");
            Console.ReadLine();
        }
    }

}
