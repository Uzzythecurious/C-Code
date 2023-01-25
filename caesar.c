// create a code that take a command line argument as a non negative int
//if no command line arguments or more then 1 command line argument return 1 with a printf error message
//if command line arg is not a decmial digit return 1 and printf Usage: ./caesar key
//ensure that if the key is bigger then 26 the program will still run upto a value of 2^31-26 (use %26 to give the remainder key/26 )
// program must  output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
//program must output cyphertext: without a new line and output the cyphered text non alphanumerical characters remain unchanged
//after outputting cyphertext the program should print newline and return 0

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_digit(string text);
string cyphertext(string plaintext);


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string text = argv[1];
        int score1 = is_digit(text); // checks if only digits been provided for the key

        if (score1 == 0) // if score is 0 then you've not entered just digits for the key
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        else if (score1 == 1)
        {
            printf("Success! \n");


            int key = atoi(argv[1]); // make the key which was a string into an int with atio function
            printf("%i \n", key);
            string plaintext = get_string("plaintext: ");//get the text to be converted to cyphertext

            printf("ciphertext: ");
            {

                for (int i = 0, n = strlen(plaintext); i < n; i++)//iterate through the plaintext
                {
                    if (plaintext[i] >= 'a' && plaintext[i] <= 'z' && islower(plaintext[i]))// a=97 z=122 looking for lowercase letters
                    {
                        int e = (plaintext[i]);
                        int f = ((e - 97) + key) % 26; //making the ascii into a 0 adding the key and %26 to cycle back around the alphabet
                        int g = 97 + f;
                        printf("%c", g);

                    }
                    else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z' && isupper(plaintext[i]))// A=65 Z=90 looking for uppercase letters
                    {
                        int h = (plaintext[i]);
                        int l = ((h - 65) + key) % 26;
                        int j = 65 + l;
                        printf("%c", j);

                    }
                    else // if not lower or uppercase or within ascii designations for a - z, A - Z just preserve puncutation
                    {
                        printf("%c", plaintext[i]);
                    }

                }
                printf("\n");
            }

        }
    }


    else if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int is_digit(string text) // will return 0 if theres any letters in the argv and 1 if just numbers checksum
{
    int score = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {

        char c = text[i];
        if (isalpha(c))
        {
            score =  0;
             //printf("%i%c key  is alpha\n", i, c);
        }
        if (isdigit(c))
        {
            score =  1;
            // printf("%i%c key  is digit\n", i, c);
        }
    }
    return score;
}


