#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)

{
    int number = get_positive_int("Height: ");

    for (int height = 0; height < number; height++)
    {
        for (int spaces = number - height - 2; spaces >= 0; spaces--)
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("  ");
        for (int row2 = 0; row2 <= height; row2++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(string prompt) 

{
    int number;
    do
    {
        number = get_int("%s", prompt);
    }
    while (number < 1 || number > 8);
    return number;
}