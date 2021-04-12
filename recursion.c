#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("How many bricks? ");

    for (int i = 0; i < height; i++)
    {
        for (int space = i; space < height - 1; space++)
        {
            printf(" ");
        }
        for (int block = 0; block < i + 1; block++)
        {
            printf("#");
        }
        printf("  ");
        for (int right = 0; right < i + 1; right++)
        {
            printf("#");
        }
        printf("\n");
    }
}
