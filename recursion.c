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
    // Base case
    if (x == 0)
        return;

    // Recursive case! Behold this function calling itself \o/
    pyramid_builder(x - 1, y);

    y = y - x; // spaces to right-align the left half
    for (int n = 0; n < y; n++)
        printf(" ");
    for (int left = 0; left < x; left++)
        printf("#");
    printf("  "); // space between two halves
    for (int right = 0; right < x; right++)
        printf("#");
    printf("\n");
}
