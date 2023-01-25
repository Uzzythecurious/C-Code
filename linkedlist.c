#include <stdio.h>
#include <stdlib.h>

//make a node struct for the linked list
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    //give a pointer value to first block in the list
    node *n = malloc(sizeof(node));
    //assign value to the first block in list with pointer to end
    if (n != NULL)
    {
        n -> number = 1;
        n -> next = NULL;
    }

    //give the list a name
    list = n;

    n = malloc(sizeof(node))//assign a new block somewhere in memory

    if (n != NULL)
    {
        n -> number = 2;
        n -> next = NULL;
    }

    list->next = n; //make the value of the last n in the new node null
                    //to signify the end of the list

    n = malloc(sizeof(node));
    if (n != NULL)
    {
    n->number = 3;
    n->next = NULL;
    }

list->next->next = n; //make the value of the last n in the new node null
                      
    //error checking
    else { return 1; }
    //free memory allocated
    free(n);
}