using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace PhotoCooperative
{
    /// <summary>
    /// Interaction logic for Checkout.xaml
    /// </summary>

    public partial class Checkout : System.Windows.Window
    {
        private PrintList shoppingCart;
        public PrintList ShoppingCart { set { shoppingCart = value; } }

        private CardBrand selectedCard = CardBrand.NotSelected;



        public Checkout()
        {
            InitializeComponent();
        }



        public void OnCardSelected(object sender, EventArgs e)
        {
            RadioButton rb = sender as RadioButton;
            string rbName = rb.Name;
            switch (rbName)
            {
                case "Visa":
                    selectedCard = CardBrand.Visa;
                    break;
                case "MasterCard":
                    selectedCard = CardBrand.MasterCard;
                    break;
                case "AmericanExpress":
                    selectedCard = CardBrand.AmericanExpress;
                    break;
                default:
                    selectedCard = CardBrand.Discover;
                    break;
            }
        }

        public void ProcessOrderForCart(object sender, RoutedEventArgs e)
        {
            String creditCardNumber = ccNumber.Text;

            if (selectedCard == CardBrand.NotSelected)
            {
                MessageBox.Show("Please select a credit card type", "Uh oh",
                   MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {

                if (CreditCardValidator.Validate(selectedCard, creditCardNumber))
                {
                    ProcessResults.Content = "Validated";
                }
                else
                {
                    ProcessResults.Content = "Pardon me, there's a call for you...";
                }
            }

        }     // end method
    }        // end class
}           // end namespace