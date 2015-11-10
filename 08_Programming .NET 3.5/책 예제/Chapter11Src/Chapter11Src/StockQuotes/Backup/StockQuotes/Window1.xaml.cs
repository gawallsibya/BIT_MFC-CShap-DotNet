using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;


namespace StockQuotes
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void GetQuote(object sender, RoutedEventArgs e)
        {
            String tickerSymbol = StockTickerTextBox.Text;
            StockQuote sq;

            YahooQuotesClient client = new YahooQuotesClient();
            // Use the 'client' variable to call operations on the service.

            sq = client.GetQuoteForStockSymbol(tickerSymbol);

            // Always close the client.
            client.Close();

            // Now we can set the variables on the page
            LastTradePrice.Content = sq.LastTradePrice;
            TradeDate.Content = sq.DateOfTrade;
            LastTradeTime.Content = sq.TimeOfTrade;
            DaysRange.Content = sq.DaysRange;
            DaysChange.Content = sq.Change;
            DaysPercentage.Content = sq.PercentageChange;
            CompanyName.Content = sq.CompanyName;


        }

    }
}
