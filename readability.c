#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//the objective of readability is to use the Coleman-Liau index to grade an inputted text.
//Coleman-Liau index = index = 0.0588 * L - 0.296 * S - 15.8, L= average number of letters per 100 word, S= average number of sentances per 100 words

int count_letters(string text); //proto function to count number of letters in text
int count_words(string text);  //proto function to count the spaces hence the words
int count_end(string text); //proto func to count sentance end

int main(void)
{
    //get input text from the user
    string text = get_string("Text: ");

    //print output of cuntion of count letters witrh text inputted
    int score1 = count_letters(text);
    int score2 = count_words(text);
    int score3 = count_end(text);
    //printf("%i letter(s)\n", score1);
    //printf("%i words(s)\n", score2);
    //printf("%i sentance(s)\n", score3);

    //grading to formula index = 0.0588 * L - 0.296 * S - 15.8 make sure its a whole number
    float l = (((float) score1) / ((float) score2) * 100);  // L = letters / words * 100
    float s = (((float) score3) / ((float) score2) * 100);  // s  = sentance/ words * 100
    float cl_index = ((0.0588 * l) - (0.296 * s) - 15.8);  // getting the raw grade as a float
    int c = round(cl_index); // converting the grade to a round int


    //checking if grade is below 1 or 16 and above
    if (c < 1)
    {
        printf("Before Grade 1\n");
    }

    if (c >= 1 && c < 16)
    {
        printf("Grade %i\n", c); //printing the final grade
    }

    if (c >= 16)
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text)
{
    int score = 0;

    //forloop to count all the letters in the text
    for (int i = 0, len = strlen(text); i <= len; i++)
    {
        char c = text[i]; //cast the string of text to individual chars at index i
        if (isalpha(text[i]))//check if the char ar index i is alphanumeric
        {
            score++;//if it is alphanumeric count it as a 1 and add to score
        }

    }
    return score;
}

int count_words(string text)

{
    int score2 = 1; //the first word will not begin with a space hence the counter starts with 1.

    //forloop to count all the spaces in the text
    for (int j = 0, len = strlen(text); j <= len; j++)
    {
        char c = text[j]; //cast the string of text to individual chars at index j
        if (isspace(text[j]))//check if the char ar index j is a space
        {
            score2++;//if it is a space count it as a 1 and add to score
        }

    }
    return score2;
}

//proto name
int count_end(string text)
{
    int score3 = 0; //the first word will not begin with a space hence the counter starts with 1.

    //forloop to count all the spaces in the text
    for (int k = 0, len = strlen(text); k <= len; k++)
    {
        if (text[k] == '.')
        {
            score3++;//if it is a . count it as a 1 and add to score
        }
        else if (text[k] == '!')
        {
            score3++;//if it is a ! count it as a 1 and add to score
        }
        else if (text[k] == '?')
        {
            score3++;//if it is a ? count it as a 1 and add to score
        }

    }
    return score3;

}
