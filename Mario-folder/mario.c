#include <cs50.h>
#include <stdio.h>

// Function declarations
void print_spaces(int count);
void print_hashes(int count);
// void print_gap(void);

int main(void)
{
    int height;

    // Prompt user for height until a valid input is given
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build the pyramid
    for (int i = 1; i <= height; i++)
    {
        print_spaces(height - i);
        print_hashes(i);
        // print_gap();
        // print_hashes(i);
        printf("\n");
    }

    return 0;
}

// Function to print spaces
void print_spaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" ");
    }
}

// Function to print hashes
void print_hashes(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("#");
    }
}

// // Function to print the gap between pyramids
// void print_gap(void)
// {
//     printf("  ");
// }
