#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv [1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int j = atoi(argv[1]);

    string plaintext =get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int k = 0; k < strlen(plaintext); k++)
    {
        if (isupper(plaintext[k]))
        {
            printf("%c", (plaintext[k] - 65 + j) % 26 + 65);

        }
        else if (islower(plaintext[k]))
        {
            printf("%c", (plaintext[k] - 97 + j) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[k]);
        }
    }
    printf("\n");
}