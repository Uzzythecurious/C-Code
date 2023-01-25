#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet a,b,c onwards
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // TODO: Print the winner
}

int compute_score(string word)
{
    //set up a counter for score to be added to as you iterate through the word
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            //the capital letters are 65+ wharever letter you have to A is equivelevent to 65 in ascii so if the first letter of word is
            // A then add to the score the value at points at the index of 65 - 65 (A-A) to get 0 which is 1 point
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            //lowercase a is 97
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
