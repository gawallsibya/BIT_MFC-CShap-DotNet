using System;
using System.Collections.Generic;

namespace Singleton
{
    class Program
    {
        /// Entry point into console application.
        /// </summary>
        static void Main()
        {
            // What happens when we ask for the load distributor 10 times?
            MailDelivery m1 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m2 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m3 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m4 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m5 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m6 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m7 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m8 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m9 = MailDelivery.GetSMTPLoadDistributor();
            MailDelivery m10 = MailDelivery.GetSMTPLoadDistributor();

            // Because we are creating a singleton, each instance should be the same
            // Trust but verify!
            if (m1 == m2 && m2 == m3 && m3 == m4 && m4 == m5 && 
                m5 == m6 && m6 == m7 && m7 == m8 && m8 == m9 && m9 == m10)
            {
                Console.WriteLine("Verified. Just one instance ever created.\n");
            }

            // distribute 100 outbound email requests for a smtp server
            MailDelivery md = MailDelivery.GetSMTPLoadDistributor();
            for (int i = 0; i < 100; i++)
            {
                Console.WriteLine(md.SmtpServer.Name+" @ "+md.SmtpServer.IP);
            }
        
            // When the user hits enter the console will quit...
            Console.Read();        
        }
    }
    
    // Singleton

    sealed class MailDelivery
    { 
        // Static members are initialized immediately when class is 
        // loaded for the first time. You should note that .NET guarantees 
        // thread safety for static initialization. This is a great thing, 
        // because thread safety can be a hard thing to do on your own.

        private static readonly MailDelivery instance = 
            new MailDelivery();

        private List<SMTPHost> smtpServers = new List<SMTPHost>();

        private Random random = new Random();

        public SMTPHost SmtpServer
        {
            get
            {
                int r = random.Next(smtpServers.Count);
                return smtpServers[r];
            }
        }

        // private constructor -- no going around making your own thank you
        private MailDelivery() 
        {
            // List of available smtp servers
            smtpServers.Add(new SMTPHost("Mail 1","192.168.0.100"));
            smtpServers.Add(new SMTPHost("Mail 2","192.168.0.101"));
            smtpServers.Add(new SMTPHost("Mail 3","192.168.0.102"));
            smtpServers.Add(new SMTPHost("Mail 4","192.168.0.103"));
            smtpServers.Add(new SMTPHost("Mail 5","192.168.0.104"));
            smtpServers.Add(new SMTPHost("Mail 6","192.168.0.105"));
            smtpServers.Add(new SMTPHost("Mail 7","192.168.0.106"));
            smtpServers.Add(new SMTPHost("Mail 8","192.168.0.107"));
            smtpServers.Add(new SMTPHost("Mail 9","192.168.0.108"));
            smtpServers.Add(new SMTPHost("Mail 10","192.168.0.109"));
        } 

        public static MailDelivery GetSMTPLoadDistributor()
        {
            return instance;
        }
        

    }

    // Simple server machine
    class SMTPHost 
    {
        private string name;
        private string ip;

        public SMTPHost(string name, string ip)
        {
            this.name = name;
            this.ip = ip;
        }
        public string Name
        {
            get { return name; }
        }
        public string IP
        {
            get { return ip; }
        }
    }    
}

