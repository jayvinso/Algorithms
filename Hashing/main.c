/* Author: Jayden Vinson */

/* standard library imports */
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

/* my hasthable implemented with chained hashing*/
#include "hash_table.h"
#include "main.h"

/* pound defines for clairty */
#define INSERTION 'i'
#define DELETION 'd'

/* i want to grab a number from the user. */
int grab_num()
{
    int num;
    printf("Please enter a valid number: \n");
    if(!scanf("%d",&num)) 
    {
        num = grab_num();
    }
    return num;
}

/* how many buckets would the user like. */
int how_many_buckets()
{
    int num;
    printf("How many buckets would you like: \n");
    if(!scanf("%d",&num)) 
    {
        num = how_many_buckets();
    }
    return num;
}

/* what action should i perform. just grabs the char. */
char what_to_do_with_num()
{
    printf("Type I to insert previous number.\nType D to delete previous number from hashmap\n");
    char input = tolower(getchar());
    if(input == 'i' || input == 'd') return input;
    printf("Please enter a valid input.\n");
    return what_to_do_with_num();
}

/* true if i should run again. false if not. */
bool run_again()
{
    printf("Type C to run again.\nType any other value to stop.\n");
    return(tolower(getchar()) == 'c');
}


/* i call upon my minions to do most of the heavy lifting. */
int main()
{
    /* ask the user how many buckets they want. */
    int num_buckets = how_many_buckets();

    /* create hashtable */
    void *hash_table = create_hashmap(num_buckets);

        do {
        /* grab a number from the user. */
        int num = grab_num();

         /* what to do with that number. */
        char action = what_to_do_with_num();

        /*perform action with number. */
        switch(action)
        {
            case(INSERTION):
                add_to_hashmap(hash_table,num,num_buckets);
                break;
            case(DELETION):
                delete_from_hashmap(hash_table,num,num_buckets);
        }   

        /* puts the data into the console */
        print_hashmap(hash_table,num_buckets);

        /* prompt the user if they want to run again */
        }while(run_again());
    
        free_memory(hash_table,num_buckets);
        return EXIT_SUCCESS;
}