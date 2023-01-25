#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? y/n? ");

    //do not forget to compare you must use ==
    //also when comparing charactors or not a string use ''
    if (c == 'y' || c=='Y')
    {
        printf("Agree.\n");
    }
    else if (c == 'n' || c=='N')
    {
        printf("Not agreed.\n");
    }
    else
    {
        printf("Pick y or n.\n");
    }
}