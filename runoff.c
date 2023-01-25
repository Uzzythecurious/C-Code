#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //check that the name of the candidate name is in the string name, then update the global preferences array to indiacate that voter has
    //that candidate as their rank preference. if sucessful return true else return false.

    //iterate through how many candidates there are, see what name the person put in, if it exists, if so assign their preferences
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {

            preferences[voter][rank] = i;
            return true;
        }
    }


    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    //iterate through votercount and then the candidate count, find the candidate whos as position 0 in that voters preferences
    // then add 1 to their vote count in the candidates array and break the loop once found only if that candidate hasn't already been eliminated

    for (int i = 0 ; i < voter_count ; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_vote_preference = preferences[i][j];

            if (candidates[candidate_vote_preference].eliminated == false)
            {
                candidates[candidate_vote_preference].votes++;
                break;
            }
            else if (candidates[candidate_vote_preference].eliminated == true)
            {
                continue;
            }

            return;
        }
    }

}


// Print the winner of the election, if there is one
bool print_winner(void)
{
    //iterate through the voter_count to check if any of the candidates have more then half the voter_count indicating theybe already won
    //if none of them have then we go to the find minimum vote so start a run off election.
    for (int j = 0; j < voter_count; j++)
    {
        int majority_vote = voter_count / 2;
        if (candidates[j].votes > majority_vote)
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }
    return false;

}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
//set an int minvotes, update it everytime you find the lowest number and compares everyones votes to it, start it off at the max number of voters
    int minvote = MAX_VOTERS;
    //loop through the candidates, and find who is still in the election ands then who has the smallest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < minvote)
        {
            minvote = candidates[i].votes;
        }
    }
//once the loop has finished, minvote will be the lowest amount of votes assigned to any candidate
    return minvote;
}

// Return false if the election is tied between all candidates votes are equal to the minimum votes.
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //check to see if within the current candidates there is someone who has more then the min votes if so its not a tie
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    //conversely if everyone has a vote number == min then its a tie
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
//find any candidate that has the minimum number of votes and eliminate them
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
