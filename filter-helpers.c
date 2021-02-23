// include header files

// For this problem, CS50 provides a lot of distribution code which I don't 
// want to commit here, so this file will not compile or do much on its own
// but it will contain the filter functions I wrote for the problem:

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;
            int average = round((r + g + b) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * r + .769 * g + .189 * b);
            int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
            int sepiaBlue = round(.272 * r + .534 * g + .131 * b);

            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // Now loop over pixels in this row and make a reversed row
        // https://www.techiedelight.com/reverse-array-c/
        RGBTRIPLE reversed[width];
        for (int j = 0; j < width; j++)
        {
            reversed[width - 1 - j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = reversed[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Create new two dimensional array of pixels for blurred image
    RGBTRIPLE blurred[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float totalR = image[i][j].rgbtRed;
            float totalG = image[i][j].rgbtGreen;
            float totalB = image[i][j].rgbtBlue;

            int box = 1; // Count neighbours for this pixel

            // Look for neighbours above (but not if top row itself)
            if (i != 0)
            {
                totalR += image[i - 1][j].rgbtRed;
                totalG += image[i - 1][j].rgbtGreen;
                totalB += image[i - 1][j].rgbtBlue;
                box++;

                if (j != 0) // look diagonally up left
                {
                    totalR += image[i - 1][j - 1].rgbtRed;
                    totalG += image[i - 1][j - 1].rgbtGreen;
                    totalB += image[i - 1][j - 1].rgbtBlue;
                    box++;
                }

                if (j != width - 1) // look diagonally up right
                {
                    totalR += image[i - 1][j + 1].rgbtRed;
                    totalG += image[i - 1][j + 1].rgbtGreen;
                    totalB += image[i - 1][j + 1].rgbtBlue;
                    box++;
                }
            }

            // Look for neighbours below (but not if last row itself)
            if (i != height - 1)
            {
                totalR += image[i + 1][j].rgbtRed;
                totalG += image[i + 1][j].rgbtGreen;
                totalB += image[i + 1][j].rgbtBlue;
                box++;

                if (j != 0) // look diagonally down left
                {
                    totalR += image[i + 1][j - 1].rgbtRed;
                    totalG += image[i + 1][j - 1].rgbtGreen;
                    totalB += image[i + 1][j - 1].rgbtBlue;
                    box++;
                }

                if (j != width - 1) // look diagonally down right
                {
                    totalR += image[i + 1][j + 1].rgbtRed;
                    totalG += image[i + 1][j + 1].rgbtGreen;
                    totalB += image[i + 1][j + 1].rgbtBlue;
                    box++;
                }
            }

            // Look for neighbours to the direct left
            if (j != 0)
            {
                totalR += image[i][j - 1].rgbtRed;
                totalG += image[i][j - 1].rgbtGreen;
                totalB += image[i][j - 1].rgbtBlue;
                box++;
            }

            // Look for neighbours to the direct right
            if (j != width - 1)
            {
                totalR += image[i][j + 1].rgbtRed;
                totalG += image[i][j + 1].rgbtGreen;
                totalB += image[i][j + 1].rgbtBlue;
                box++;
            }

            // Calculate average values and assign to current pixel
            blurred[i][j].rgbtRed = round(totalR / box);
            blurred[i][j].rgbtGreen = round(totalG / box);
            blurred[i][j].rgbtBlue = round(totalB / box);
        }
    }

    // Modify original image array with new blurred values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blurred[i][j].rgbtRed;
            image[i][j].rgbtGreen = blurred[i][j].rgbtGreen;
            image[i][j].rgbtBlue = blurred[i][j].rgbtBlue;
        }
    }
    return;
}
