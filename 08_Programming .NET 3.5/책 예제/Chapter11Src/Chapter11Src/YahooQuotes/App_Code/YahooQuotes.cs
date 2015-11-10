using System;
using System.Collections.Generic;
using System.Text;
using System.Web;
using System.Net;
using System.IO;
using System.ServiceModel;
using System.Runtime.Serialization;

/* A WCF service consists of a contract (defined below as IYahooQuote), 
 * a class which implements that interface (see YahooQuote),
 * and configuration entries that specify behaviors associated with 
 * that implementation (see <system.serviceModel> in web.config)*/
[ServiceContract]
public interface IYahooQuotes
{

    [OperationContract]
    string TestService(int intParam);

    [OperationContract]
    StockQuote GetQuoteForStockSymbol(String aSymbol);


}


/* Use a data contract as illustrated in the sample below to add StockQuote 
 * types to service operations*/
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

        // Use the data dictionary at the end of the big listing to 
        // decipher the end of this url.
        String url = "http://quote.yahoo.com/d/quotes.csv?s=" + tickerSymbol + "&f=l1d1t1pomvc1p2n";

        // ok, now that we have a URL, we'll go get some data which will return to us
        // in a nicely packaged csv format.
        webRequest = HttpWebRequest.Create(url);
        webResponse = webRequest.GetResponse();

        // Now we'll put it in a stream buffer to make text replacement easier
        using (StreamReader sr = new StreamReader(webResponse.GetResponseStream()))
        {
            buffer = sr.ReadToEnd();
            sr.Close();
        }

        // We're going to strip out the " marks
        buffer = buffer.Replace("\"", "");
        // Now we'll put it in a char array
        bufferList = buffer.Split(new char[] { ',' });

        sq.LastTradePrice = bufferList[0]; // 1l
        sq.DateOfTrade = bufferList[1]; // d1
        sq.TimeOfTrade = bufferList[2]; // t1
        sq.PreviousClose = bufferList[3]; // p
        sq.Open = bufferList[4]; // o
        sq.DaysRange = bufferList[5]; // m
        sq.Volume = bufferList[6]; // v
        sq.Change = bufferList[7]; // c1
        sq.PercentageChange = bufferList[8]; // p2
        sq.CompanyName = bufferList[9]; // n

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

/*
 *  Yahoo!Finance stock quote data dictionary
 *  
      Symbol                            s
      Name                              n
      Last Trade (With Time)            l
      Last Trade (Price Only)           l1
      Last Trade Date                   d1
      Last Trade Time                   t1
      Last Trade Size                   k3
      Change and Percent Change         c
      Change                            c1
      Change in Percent                 p2
      Ticker Trend                      t7
      Volume                            v
      Average Daily Volume              a2
      More Info                         i
      Trade Links                       t6
      Bid                               b
      Bid Size                          b6
      Ask                               a
      Ask Size                          a5
      Previous Close                    p
      Open                              o
      Day's Range                       m
      52-week Range                     w
      Change From 52-wk Low             j5
      Pct Chg From 52-wk Low            j6
      Change From 52-wk High            k4
      Pct Chg From 52-wk High           k5
      Earnings/Share                    e
      P/E Ratio                         r
      Short Ratio                       s7
      Dividend Pay Date                 r1
      Ex-Dividend Date                  q
      Dividend/Share                    d
      Dividend Yield                    y
      Float Shares                      f6
      Market Capitalization             j1
      1yr Target Price                  t8
      EPS Est. Current Yr               e7
      EPS Est. Next Year                e8
      EPS Est. Next Quarter             e9
      Price/EPS Est. Current Yr         r6
      Price/EPS Est. Next Yr            r7
      PEG Ratio                         r5
      Book Value                        b4
      Price/Book                        p6
      Price/Sales                       p5
      EBITDA                            j4
      50-day Moving Avg                 m3
      Change From 50-day Moving Avg     m7
      Pct Chg From 50-day Moving Avg    m8
      200-day Moving Avg                m4
      Change From 200-day Moving Avg    m5
      Pct Chg From 200-day Moving Avg   m6
      Shares Owned                      s1
      Price Paid                        p1
      Commission                        c3
      Holdings Value                    v1
      Day's Value Change                w1,
      Holdings Gain Percent             g1
      Holdings Gain                     g4
      Trade Date                        d2
      Annualized Gain                   g3
      High Limit                        l2
      Low Limit                         l3
      Notes                             n4
      Last Trade (Real-time) with Time  k1
      Bid (Real-time)                   b3
      Ask (Real-time)                   b2
      Change Percent (Real-time)        k2
      Change (Real-time)                c6
      Holdings Value (Real-time)        v7
      Day's Value Change (Real-time)    w4
      Holdings Gain Pct (Real-time)     g5
      Holdings Gain (Real-time)         g6
      Day's Range (Real-time)           m2
      Market Cap (Real-time)            j3
      P/E (Real-time)                   r2
      After Hours Change (Real-time)    c8
      Order Book (Real-time)            i5
      Stock Exchange                    x

*/