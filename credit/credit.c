#include <stdio.h>
#include <cs50.h>

bool luhn_algorithm(long card_number);
string get_card_type(long card_number);
int get_length(long number);

int main(void)
{
    long card_number;

    while (true)
    {
        // Get the card number from the user
        card_number = get_long("Enter your card number: ");

        // Check if the card number is of valid length (at least 2 digits)
        if (get_length(card_number) == false)
        {
            printf("INVALID\n");  // Print INVALID for invalid length
        }
        else
        {
            // Check if the card number is valid
            if (luhn_algorithm(card_number))
            {
                // Determine and print the card type
                printf("%s\n", get_card_type(card_number));
                return 0;  // Exit the loop if a valid card number is entered
            }
            else
            {
                printf("INVALID\n");  // Print INVALID for failed Luhn algorithm
            }
        }
    }

    return 0;
}

bool luhn_algorithm(long card_number)
{
    int total_sum = 0;
    bool alternate = false;

    // Process each digit starting from the end
    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total_sum += digit;
        alternate = !alternate;
    }

    return (total_sum % 10 == 0);
}

string get_card_type(long card_number)
{
    int length = get_length(card_number);
    long start_digits = card_number;

    // Reduce start_digits to the first two digits
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // Check for American Express
    if (length == 15 && (start_digits == 34 || start_digits == 37))
    {
        return "AMEX";
    }
    // Check for MasterCard
    else if (length == 16 && (start_digits >= 51 && start_digits <= 55))
    {
        return "MASTERCARD";
    }
    // Check for Visa
    else if ((length == 13 || length == 16) && (start_digits / 10 == 4))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}
