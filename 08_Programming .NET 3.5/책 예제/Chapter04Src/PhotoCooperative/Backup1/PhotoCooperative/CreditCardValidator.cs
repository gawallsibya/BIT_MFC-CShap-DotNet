using System;
using System.Collections.Generic;
using System.Text;

namespace PhotoCooperative
{
    public enum CardBrand
    {
        NotSelected, MasterCard, BankCard, Visa, AmericanExpress, Discover, DinersClub, JCB
    };

    public static class CreditCardValidator
    {

        public static bool Validate(CardBrand cardBrand, string cardNumber)
        {

            byte[] number = new byte[16]; // card number to validate

            // Remove non-digits
            int length = 0;
            for (int i = 0; i < cardNumber.Length; i++)
            {
                if (char.IsDigit(cardNumber, i))
                {
                    if (length == 16) return false; // card has too many digits
                    number[length++] = byte.Parse(cardNumber[i].ToString());
                }
            }

            // To validate a card, you need to test length then prefix...
            switch (cardBrand)
            {
                case CardBrand.BankCard:
                    if (length != 16)
                        return false;
                    if (number[0] != 5 || number[1] != 6 || number[2] > 1)
                        return false;
                    break;

                case CardBrand.MasterCard:
                    if (length != 16)
                        return false;
                    if (number[0] != 5 || number[1] == 0 || number[1] > 5)
                        return false;
                    break;

                case CardBrand.Visa:
                    if (length != 16 && length != 13)
                        return false;
                    if (number[0] != 4)
                        return false;
                    break;

                case CardBrand.AmericanExpress:
                    if (length != 15)
                        return false;
                    if (number[0] != 3 || (number[1] != 4 && number[1] != 7))
                        return false;
                    break;

                case CardBrand.Discover:
                    if (length != 16)
                        return false;
                    if (number[0] != 6 || number[1] != 0 || number[2] != 1 || number[3] != 1)
                        return false;
                    break;

                case CardBrand.DinersClub:
                    if (length != 14)
                        return false;
                    if (number[0] != 3 || (number[1] != 0 && number[1] != 6 && number[1] != 8)
                       || number[1] == 0 && number[2] > 5)
                        return false;
                    break;

            }

            // Now we use the classic Luhn Algorithm to validate
            int sum = 0;
            for (int i = length - 1; i >= 0; i--)
            {
                if (i % 2 == length % 2)
                {
                    int n = number[i] * 2;
                    sum += (n / 10) + (n % 10);
                }
                else
                    sum += number[i];
            }
            return (sum % 10 == 0);

            /*
             * [From http://en.wikipedia.org/wiki/Luhn_algorithm ]
             * 
             * 
             * The Luhn algorithm or Luhn formula, also known as the "modulus 10" or 
             * "mod 10" algorithm, is a simple checksum formula used to validate a 
             * variety of identification numbers, such as credit card numbers and 
             * Canadian Social Insurance Numbers. It was created by IBM scientist 
             * Hans Peter Luhn and described in US Patent 2,950,048, filed on 
             * January 6, 1954 and granted on August 23, 1960. 
             * 
             * The algorithm is in the public domain and is in wide use today. It is 
             * not intended to be a cryptographically secure hash function; it was 
             * designed to protect against accidental errors, not malicious attacks. 
             * Most credit cards and many government identification numbers use the 
             * algorithm as a simple method of distinguishing valid numbers from 
             * collections of random digits.
             * 
             */
        }
    }
}
