#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do

    {

        height = get_int("Height: ");

    }

    while ((height > 8) || (height <= 0));


//start a counter for every number in height

    for (int i = 0; i < height; i++)
    {
//put s number of space which starts at one dot less then the height and count down for every iteration

        for (int s = (height - 1); s > i; s--)
        {
            printf(" ");
        }
//put a hash for every iteration through the height counter

        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
//add a # and two spaces for every line in height

        printf("#  ");
//put #'s on every line that correspond to the counter which corresponds to the height
        for (int o = 0; o <= i; o++)
        {
            printf("#");
        }
//new line at the end

        printf("\n");
    }
}