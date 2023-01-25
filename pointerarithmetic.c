#include <stdio.h>

int main(void)
{
    char * s = "HI!";
    printf("%c\n", *&s);
    printf("%c\n", *s);
    printf("%c\n", *s+1);
    printf("%p\n", &s);
    printf("%p\n", &s+1);
}