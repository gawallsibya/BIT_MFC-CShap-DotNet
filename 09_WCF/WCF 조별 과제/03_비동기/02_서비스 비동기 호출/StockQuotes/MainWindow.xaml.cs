using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using StockQuotes.YahooQuotes;
using System.Threading;
namespace StockQuotes
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        StockQuote asd;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void GetQuote(object sender, RoutedEventArgs e)
        {
            Thread.Sleep(4000);
            String tickerSymbol = StockTickerTextBox.Text;
            

            YahooQuotesClient client = new YahooQuotesClient();
            StockQuote sq = client.GetQuoteForStockSymbol(tickerSymbol);

            LastTradePrice.Content = sq.LastTradePrice;
            TradeDate.Content = sq.DateOfTrade;
            LastTradeTime.Content = sq.TimeOfTrade;
            DaysRange.Content = sq.DaysRange;
            DaysChange.Content = sq.Change;
            DaysPercentage.Content = sq.PercentageChange;
            CompanyName.Content = sq.CompanyName;

            client.Close();
        }

        private void GetQ(object sender, RoutedEventArgs e)
        {
            String tickerSymbol = StockTickerTextBox.Text;
            YahooQuotesClient client = new YahooQuotesClient();
            
            IAsyncResult aresult = client.BeginGetQuoteForStockSymbol(tickerSymbol, GetQuoteCallback, client);

        }

        public void GetQuoteCallback(IAsyncResult ar)
        {
            Thread.Sleep(5000);
            asd = ((YahooQuotesClient)ar.AsyncState).EndGetQuoteForStockSymbol(ar);
                        
            MessageBox.Show("작업 완료");          
        }

   

        private void PrintQuote(object sender, RoutedEventArgs e)
        {            
            if( asd == null)
            {
                MessageBox.Show("작업 중");
                return;
            }
            LastTradePrice.Content = asd.LastTradePrice;
            TradeDate.Content = asd.DateOfTrade;
            LastTradeTime.Content = asd.TimeOfTrade;
            DaysRange.Content = asd.DaysRange;
            DaysChange.Content = asd.Change;
            DaysPercentage.Content = asd.PercentageChange;
            CompanyName.Content = asd.CompanyName;
            asd = null;
        }
    }
}
