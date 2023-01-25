#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get numbers from user
    int x = get_int ("x: ");
    int y = get_int ("y: ");
    
    //Divide x by y and change the int to a float 
    //remember if you leave the x and y as ints the computer will
    //do the equation from right to left 
    //it will make the x/y an int before you cast it to a float.
    float z = (float)x / (float)y;
    printf("%f\n", z);
}