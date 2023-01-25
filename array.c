#include <stdio.h>
#include <cs50.h>

//if you know the total scores and want to hardcode it
//const int TOTAL = 3;
//this decalres total a constant global variable so nothing can change it
//unless it gets amended in code.

//declare prototype with the type float
float average (int length, int array[]);

int main (void)
{
    //get the total number of scores and set that to the i in the array
    int TOTAL = get_int("How many scores?; \n");
    int scores[TOTAL];//set array with TOTAL as the [i]
    //set the inteval for length because the output of the average func
    //needs an int for its length which we want to be the total the user put in
    int length = TOTAL;
    //for loop to ask the user for [TOTAL] number of scores to put into array
    for (int i=0; i<TOTAL; i++)
    {
        scores[i]= get_int("Score: ");
    }
    printf("Average: %f\n", average (TOTAL, scores));
}
//this is the function declared earlier in our prototype.
//this takes the length of the array and divdes it by the sum of the array variables.
//the names of the input to the function do not need to be same ad the name of the
//variables being passed into that function.
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
