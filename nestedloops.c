#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //get positive int from user
    int n;
    int j;
    do
    {
        n=get_int("Width;");
        j= get_int("Height; ");
    }
    //check both n and j are positive ints
    while (n<1 && j<1);

    //using a loop to say how many times to run the first loop
    //to then run the nested loop within this loop
    //first loop says run this loop j number of times
    for (int i=0; i<j; i++)
    {
        //this loop says run this loop for n numner of times for every
        //j number of times you run the top loop

        for (int l=0; l<n; l++)
        {
            printf("?");

        }
    //now print a new line every time you iterate through j
    printf("\n");
    }

}