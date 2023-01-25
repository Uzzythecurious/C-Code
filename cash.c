#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float x;//current value of change
    int i;//counter
    int q = 25;
    int d = 10;
    int n = 05;
    int p = 1;
    int count = 0;
    //get user input
    do
    {
        x = get_float("change owed: ");
    }
    //ensure user given a number bigger then 0
    //convert that number to an int by using round
    //cannot leave that x as a float as floats do not work well in
    //equations as they are not precise enough to give correct ans
    while (x < 0);
    printf("%.2f\n", x);
    int c = round(x * 100);

    //when change is bigger then 25 see how many times 25 can be taken away
    //before it becomes smaller and add to counter
    for (i = 0; c >= q; i++)
    {
        c = c - q;
        count++;
    }
    //when more then 10 remaining check
    for (i = 0; c >= d; i++)
    {
        c = c - d;
        count++;
    }
    //printf("%i\n",count);
    //when more then 05 remaining
    for (i = 0; c >= n; i++)
    {
        c = c - n;
        count++;
    }
    //when more then 1 reamining
    for (i = 0; c >= p; i++)
    {
        c = c - p;
        count++;
    }
    printf("%i\n", count);
}