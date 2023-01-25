#include <stdio.h>// these are header files or libraries
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("Hello, %s\n", answer);
}
// you must make this code into a file after saving as hello.c by using "make hello" into the terminal
// to run you must do ./hello to run the file
// the %s is a place holder for a string type function
// the , answer is to tell the printf function what to pass into the %s
// the /n is a new line