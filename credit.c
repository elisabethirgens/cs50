#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card = get_long("Number: ");
    int checksum = 0;

    // Multiply every other digit by 2, then get sum of products digits
    long partial = card;
    long z = 10;
    int lastdigit;
    int tmp;
    while (partial > 10)
    {
        partial = card / z;
        lastdigit = partial % 10;
        tmp = lastdigit * 2;
        // Get individual digits from product
        if (tmp > 9)
        {
            tmp = tmp % 10 + tmp / 10 % 10;
        }
        checksum += tmp;
        z *= 100;
    }

    // Get sum of digits not multiplied by 2, starting from end
    long partial2 = card;
    long y = 1;
    while (partial2 > 10)
    {
        partial2 = card / y;
        checksum += partial2 % 10;      // Get last digit and add to checksum
        y *= 100;                       // Add two zeros for next loop
    }

    checksum = checksum % 10;

    // Count digits and store the result in counter
    int counter = 0;
    long copy = card;
    long x = 1;
    while (copy > 10)
    {
        counter++;
        copy = card / x;
        x *= 10;
    }

    int start;

    if (checksum == 0 && counter == 15)
    {
        start = card / pow(10, counter - 2);
        if (start == 34 || start == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (checksum == 0 && counter == 13)
    {
        start = card / pow(10, counter - 1);
        if (start == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (checksum == 0 && counter == 16)
    {
        start = card / pow(10, counter - 2);
        if (start >= 40 && start <= 49)
        {
            printf("VISA\n");
        }
        else if (start >= 51 && start <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
