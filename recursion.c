#include <cs50.h>
#include <stdio.h>

void pyramid_builder(int x, int y);

int main(void)
{
    int height = get_int("How many bricks? ");
    pyramid_builder(height, height);
}

void pyramid_builder(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int negative = i; negative <= y; negative++)
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
