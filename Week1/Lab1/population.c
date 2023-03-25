#include <stdio.h>

int main(void)
{
    //TODO Prompt for the start size
    int start;
    do{
        printf("Ending Population: ");
        scanf("%d", &start);
    }
    while (start < 9);

    //TODO Prompt for the end size
    int end;
    do{
        printf("Ending Population: ");
        scanf("%d", &end);
    }
    while (start > end);

    //Calculate the number of years untill we reach treshold
    int years;
    do{
    start = start + (start / 3) - (start / 4);
    years ++;
    }
    while (start < end);

    //Print number of year
    printf("Years: %i\n", years);
}