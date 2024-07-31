#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
int string_to_int(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure the program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = string_to_int(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Rotate the character if it's a letter
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Function to check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to convert a string to an integer
int string_to_int(string s)
{
    int number = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        number = number * 10 + (s[i] - '0');
    }
    return number;
}

// Function to rotate a character by n positions
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Rotate uppercase letters
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // Rotate lowercase letters
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        // Non-alphabetic characters remain unchanged
        return c;
    }
}
