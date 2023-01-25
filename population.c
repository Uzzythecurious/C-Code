#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ps;
    int eps;

    // TODO: Prompt for start siz
    do
    {
        scanf("%i", &ps);//get_int("Start size: ");

    }
    while (ps < 9);
// TODO: Prompt for end size
    do
    {
        eps = get_int("End size: ");
    }
    while (eps < ps);
    printf("Start size: %i\n", ps);
    printf("End size: %i\n", eps);

// keep track of years
    int years = 0;

// TODO: Calculate number of years until we reach threshold
//every year you gain n/3
//every year you lose n/4

    while (ps < eps)
    {
//division in c will auto truncate anything after decmial point
        ps = ps + (ps / 3) - (ps / 4);
        years++;
    }
    printf("Years: %i\n", years);
}