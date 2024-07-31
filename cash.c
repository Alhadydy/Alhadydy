#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents, int denomination);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Initialize variables to count coins
    int quarters, dimes, nickels, pennies;

    // Calculate number of quarters
    quarters = calculate_coins(cents, 25);
    cents -= quarters * 25;

    // Calculate number of dimes
    dimes = calculate_coins(cents, 10);
    cents -= dimes * 10;

    // Calculate number of nickels
    nickels = calculate_coins(cents, 5);
    cents -= nickels * 5;

    // Remaining cents are pennies
    pennies = cents;

    // Calculate total number of coins
    int total_coins = quarters + dimes + nickels + pennies;

    // Print the minimum number of coins
    printf("%i\n", total_coins);

    return 0;
}

// Function to calculate number of coins of a given denomination
int calculate_coins(int cents, int denomination)
{
    int count = 0;
    while (cents >= denomination)
    {
        count++;
        cents -= denomination;
    }
    return count;
}
