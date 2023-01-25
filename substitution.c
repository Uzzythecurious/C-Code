#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int checkkeylength(string key);//check the length of the key is = to 26
int checkkeyalpha(string key);// check if the key is an alphabetical charactor and not containing anything else
int checkcharrepeat(string key); //how to check if a char is repeated in the string

int main(int argc, string key[])


{

    if (argc == 2)
    {
        string text = key[1]; //placeholder for the key

        //check that the length is 26, check the characters are in the alphabet, check that the key doesn't contain repeated characters.
        int checklength = checkkeylength(text);
        int checkalpha = checkkeyalpha(text);
        int checkrepeat = checkcharrepeat(text);

        if (checklength == 1)
        {
            return 1;

        }

        if (checkalpha == 1)
        {
            return 1;
        }

        if (checkrepeat == 1)
        {
            return 1;

        }

        if (checklength > 0 || checkalpha > 0 || checkrepeat > 0)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        if (checklength == 0 && checkalpha == 0 && checkrepeat == 0)
        {
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");


            for (int i = 0, n = strlen(plaintext); i < n; i++)//iterate through the plaintext
            {
                char c = text[i];

                if (islower(plaintext[i]))  // a=97 z=122 looking for lowercase letters
                {
                    int d = (plaintext[i] - 97); //this gives the number of letters along the alphabet the plaintext letter is
                    char output = text[d]; // this takes the int d as an index to count along the key to replace the plaintext letter with
                    //the corresponding letter to that index in the key
                    printf("%c", tolower(output));
                }

                else if (isupper(plaintext[i])) // A=65 Z=90 looking for uppercase letters
                {
                    int e = (plaintext[i] - 65); //this gives the number of letters along the alphabet the plaintext letter is
                    char output1 = text[e];
                    printf("%c", toupper(output1));
                }

                else // if not lower or uppercase or within ascii designations for a - z, A - Z just preserve puncutation
                {
                    printf("%c", plaintext[i]);
                }

            }
            printf("\n");



        }


    }

    else if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


int checkkeylength(string key)
{
    if (strlen(key) == 26)
    {
        return 0;
    }
    else
    {
        printf("key != 26 in length\n");
        return 1;
    }
}

int checkkeyalpha(string key)
{
    int score = 0;
    for (int i = 0, len = strlen(key); i < len; i++)
    {

        char c = tolower(key[i]);

        if (isalpha(c))
        {
            score = 0;

        }
        if (!isalpha(c)) //could also use !isalpha(c) with an if statement here.
        {
            score = 1;
            break;
        }
    }
    return score;
}

int checkcharrepeat(string key)
{
    int dupcounter = 0;

//set a nested loop to check for if every character along the length of the string is repeated
//ie char 0 is checked against every char from 0 onwards till it reaches the end then char 1 is checked etc.
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        char c = tolower(key[i]);


        for (int j = 0; j < i ; j++)
        {

            if (c == tolower(key[j]))
            {
                dupcounter ++;
                return 1;
                break;
            }
            else
            {
                dupcounter = 0;

            }
        }

    }
    return dupcounter;
}