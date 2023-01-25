#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
    unsigned int x= 324;
    int y = sizeof(x);

    printf("%ld \n", sizeof(x));
}