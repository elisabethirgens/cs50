#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("How many bricks? ");

    for (int i = 0; i < height; i++)
    {
        for (int negative = i; negative <= height; negative++)
        {
            printf(" ");
        }
        for (int left = 0; left <= i; left++)
        {
            printf("#");
        }
        printf(" "); // space between the two halves
        for (int right = 0; right <= i; right++)
        {
            printf("#");
        }
        printf("\n");
    }
}
