using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;
using System.Web;
using System.Net;
using System.IO;

// 참고: "리팩터링" 메뉴에서 "이름 바꾸기" 명령을 사용하여 코드, svc 및 config 파일에서 클래스 이름  "Service"를 변경할 수 있습니다.

[ServiceContract]
public interface IYahooQuotes
{

    [OperationContract]
    string TestService(int intParam);

    [OperationContract]
    StockQuote GetQuoteForStockSymbol(String aSymbol);
}

public class YahooQuotes : IYahooQuotes
{
    public string TestService(int intParam)
    {
        return string.Format("You entered: {0}", intParam);
    }

    public StockQuote GetQuoteForStockSymbol(String tickerSymbol)
    {
        StockQuote sq = new StockQuote();
        string buffer;
        string[] bufferList;
        WebRequest webRequest;
        WebResponse webResponse;

        String url = 
            "http://quote.yahoo.com/d/quotes.csv?s=" + 
            tickerSymbol + 
            "&f=l1d1t1pomvc1p2n";

        webRequest = HttpWebRequest.Create(url);
        webResponse = webRequest.GetResponse();

        using (StreamReader sr = new StreamReader(webResponse.GetResponseStream()))
        {
            buffer = sr.ReadToEnd();
            sr.Close();
        }

        buffer = buffer.Replace("\"", "");
        bufferList = buffer.Split(new char[] { ',' });

        sq.LastTradePrice = bufferList[0]; 
        sq.DateOfTrade = bufferList[1]; 
        sq.TimeOfTrade = bufferList[2]; 
        sq.PreviousClose = bufferList[3]; 
        sq.Open = bufferList[4];
        sq.DaysRange = bufferList[5]; 
        sq.Volume = bufferList[6]; 
        sq.Change = bufferList[7]; 
        sq.PercentageChange = bufferList[8]; 
        sq.CompanyName = bufferList[9]; 

        return sq;
    }
}

[DataContract]
public class StockQuote
{

    [DataMember]
    public String LastTradePrice
    {
        get;
        set;
    }

    [DataMember]
    public String DateOfTrade
    {
        get;
        set;
    }

    [DataMember]
    public String TimeOfTrade
    {
        get;
        set;
    }

    [DataMember]
    public String PreviousClose
    {
        get;
        set;
    }

    [DataMember]
    public String Open
    {
        get;
        set;
    }

    [DataMember]
    public String DaysRange
    {
        get;
        set;
    }

    [DataMember]
    public String Volume
    {
        get;
        set;
    }

    [DataMember]
    public String Change
    {
        get;
        set;
    }

    [DataMember]
    public String PercentageChange
    {
        get;
        set;
    }


    [DataMember]
    public String CompanyName
    {
        get;
        set;
    }

}