#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //get all the rgb triple values at the pixel image[h][w],
    //average out the value of red green blue for each pixel in array image[h][w] make sure the float of the average = a rounded int
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;

            float avrf = (r + g + b) / 3;
            int avri = round(avrf);

            image[i][j].rgbtRed = avri;
            image[i][j].rgbtGreen = avri;
            image[i][j].rgbtBlue = avri;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //get all the rgb triple values at the pixel image[h][w],
    //get the value of red green blue for each pixel in array image[h][w]
    //impliment sepia formula accordingly
    // if the values exceed 255 then set that colours value to 255
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            float sepiar = (.393 * r) + (.769 * g) + (.189 * b);
            int sepiarint = round(sepiar);

            float sepiag = (.349 * r) + (.686 * g) + (.168 * b);
            int sepiagint = round(sepiag);

            float sepiab = (.272 * r) + (.534 * g) + (.131 * b);
            int sepiabint = round(sepiab);


            if (sepiarint > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiarint;
            }


            if (sepiagint > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiagint;
            }

            if (sepiabint > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiabint;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //take the pixel at every coloumn in every row and swap this with the pixel on horizontally opposite sides
    //itereate through the h w and create a temp value store the last pixel in there make the first pixel the last and then make the first pixel the temp
    // use j as a counter and find a way to do j++ and j-- for the same loop maybe use size of?

    for (int i = 0 ; i < height ; i++)
    {

        for (int j = 0; j < width / 2; j++) //division auto truncates any decimal after result 11/2 = 5.5 = 5
        {
            //swap the first elements with the last which is j+1
            RGBTRIPLE tmp = image[i][j]; //byte temp = the pixel at i j cast result of i j which is the pixel to a tmp value of type rgbtriple
            // temp = a

            image [i][j] = image [i][width - (j + 1)]; //  a = b
            image[i][width - (j + 1)] = tmp; // b = temp

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //create a temp value for the image.
    RGBTRIPLE temp [height][width];

    // we want to iterate through one row and one column away from the value of pixel at [height][width]
    /*  [i-1,j-1][i-1,j][i-1,j+1]
        [i,j-1]  [i,j]  [i,j+1]
        [i+1,j-1][i+1,j][i+1,j+1] */

    //first get to the location of the pixel in the temp pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)

        {
            //set up counters
            int redtot = 0;
            int greentot = 0;
            int bluetot = 0;
            float counter = 0.00;

            //loop again for [height+k][width+l]
            for (int k = -1 ; k < 2 ; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k > height - 1 || i + k < 0 || j + l > width - 1
                        || j + l < 0) //this says if counter goes out of the size of height do nothing just carry on
                    {
                        continue;
                    }

                    redtot +=  image[i + k][j + l].rgbtRed;
                    greentot += image[i + k][j + l].rgbtGreen;
                    bluetot += image[i + k][j + l].rgbtBlue;
                    counter ++;

                }
            }

            //assign the value of the rgb in the pixel to the temp value at i j
            temp [i][j].rgbtRed = round((redtot / counter));
            temp [i][j].rgbtBlue = round((bluetot / counter));
            temp [i][j].rgbtGreen = round((greentot / counter));



        }
    }
    //now do another for loop to cast the temp values to the actual values so that the image isnt
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image [i][j].rgbtRed = temp [i][j].rgbtRed;
            image [i][j].rgbtGreen = temp [i][j].rgbtGreen;
            image [i][j].rgbtBlue = temp [i][j].rgbtBlue;
        }
    }
    return;
}
