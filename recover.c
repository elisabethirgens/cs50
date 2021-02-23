#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Ensure user sends in a single argument
    if (argc != 2)
    {
        printf("Usage: .recover image\n");
        return 1;
    }

    // Open memory card in read mode
    FILE *fileptr = fopen(argv[1], "r");
    if (fileptr == NULL)
    {
        printf("Could not open this file\n");
        return 1;
    }

    // Set up the initial JPEG file
    int jpegcount = 0;
    char filename[8]; // File name characters + extra for end of string
    sprintf(filename, "%03i.jpg", jpegcount);
    FILE *img = fopen(filename, "w");
    if (img == NULL)
    {
        printf("Could not open image\n");
        return 1;
    }

    // For the sake of this CS50 problem, we can assume that:
    // JPEGs are stored back-to-back on a brand new memory card
    // with a FAT file system where each block is 512 bytes
    int BLOCK_SIZE = 512;

    // Dynamically allocate memory for an array of bytes on the heap
    BYTE *buffer = malloc(BLOCK_SIZE * sizeof(BYTE));
    if (buffer == NULL)
    {
        return 1;
    }

    // Repeat until we reach the end of the memory card
    while (fread(buffer, BLOCK_SIZE, 1, fileptr))
    {
        // Loop has now read a block of 512 bytes into a buffer

        // Check if first 4 bytes are a jpegheader
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpegcount == 0)
            {
                // Start writing directly to the very first JPEG file
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
            else
            {
                // Not our first JPEG, so close previous and open next
                fclose(img);
                fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }

            // Increment counter and update filename string for next time
            jpegcount++;
            sprintf(filename, "%03i.jpg", jpegcount);
        }
        else
        {
            // Continue writing blocks when JPEG previously found
            if (jpegcount > 0)
            {
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }
    }

    free(buffer);
    fclose(img);
    fclose(fileptr);
    return 0;
}
