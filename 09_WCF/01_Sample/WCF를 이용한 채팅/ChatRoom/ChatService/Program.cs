// �����ڷ�: Nikola Paljetak
// ������: �ڰ���(HOONS)
// ��� Ŀ�´�Ƽ : HOONS��� - http://www.hoonsbara.com


using System;
using System.Collections.Generic;
using System.Text;
using System.ServiceModel;
using System.Configuration;

namespace NikeSoftChat
{
  class Program
  {
    static void Main(string[] args)
    {

      Uri uri = new Uri(ConfigurationManager.AppSettings["addr"]);
      ServiceHost host = new ServiceHost(typeof(NikeSoftChat.ChatService), uri);
      host.Open();
      Console.WriteLine("ä�� ���񽺸� �����մϴ�. {0}", uri.ToString());
      Console.WriteLine("���߽÷��� ���͸� �����ּ���..");
      Console.ReadLine();
      host.Abort();
      host.Close();
    }
  }
}
