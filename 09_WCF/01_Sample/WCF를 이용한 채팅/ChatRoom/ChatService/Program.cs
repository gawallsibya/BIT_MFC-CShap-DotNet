// 참고자료: Nikola Paljetak
// 만든이: 박경훈(HOONS)
// 닷넷 커뮤니티 : HOONS닷넷 - http://www.hoonsbara.com


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
      Console.WriteLine("채팅 서비스를 시작합니다. {0}", uri.ToString());
      Console.WriteLine("멈추시려면 엔터를 눌러주세요..");
      Console.ReadLine();
      host.Abort();
      host.Close();
    }
  }
}
