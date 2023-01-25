#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get int from user
    int x = get_int("x: ");
    int y = get_int("y: ");

    // compare x and y
    if (x<y)
    {
        printf("x is less then y\n");
    }
    else if (x>y)
    {
        printf("x is more then y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}