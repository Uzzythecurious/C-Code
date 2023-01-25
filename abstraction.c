#include <stdio.h>
// we want to print meow 3 times these are 3 different ways
//as you can see we put the meow custom func at the bottom
//the compiler reads top to bottom so we need to give it a hint
//this following void meow is a protofunction
//it makes the program look further on for the actual custom func
void meow(int n);
//declare your prototype
int main(void)
{

    meow(3);
    }
/*{
    printf("meow");
    printf("meow");
    printf("meow");
}*/
/*{
    for (int i=0; i<3; i++)
{
    printf("meow\n");
}*/
/*
    {
    for (int i=0; i<3; i++)
    {
    meow();
    }*/


//custom functions
void meow(int n)
{
    for (int i=0; i<n; i++)
   {
       printf("meow\n");

   }
}
