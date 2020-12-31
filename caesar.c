#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Ensure single command-line argument
    if (argc == 2)
    {
        // Check if provided cli arg is a valid key
        bool only_digits = true;
        string cli_arg = argv[1];
        for (int i = 0; i < strlen(cli_arg); i++)
        {
            if (!isdigit(cli_arg[i]))
            {
                only_digits = false;
            }
        }
        if (only_digits == true)
        {
            int key = atoi(cli_arg);

            // Commence shifting of characters to cipher!
            string plain = get_string("plaintext: ");
            int n = strlen(plain);

            for (int i = 0; i < n ; i++)
            {

                if (islower(plain[i]) || isupper(plain[i]))
                {
                    plain[i] = (plain[i] + key);
                }

            }
            printf("ciphertext: %s\n", plain);
        }
        else
        {
            printf("Usage: .caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: .caesar key\n");
        return 1;
    }

}