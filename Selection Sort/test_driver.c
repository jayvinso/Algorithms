/* Made by: Jayden Vinson */

/* standard imports */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* include the other header */
#include "selection_sort.h"

/* include my own header file last*/
#include "test_driver.h"


// size of each array is always 10
#define SIZE_ARRAY 10

void run_tests()
{
    test1();
    test2();
    test3();
}

/* already sorted */
int test1()
{
    int myNumbers[] = {1, 2 , 3, 4, 5 ,6 ,7 , 8 , 9,10};
    selection_sort(myNumbers);
}

/* opposite of sorted */
int test2()
{
    int myNumbers[] = {10,9 , 8, 7, 6, 5, 4 ,3 ,2 ,1};
    selection_sort(myNumbers);
}

/* random numbers. different every time it is ran */
int test3()
{
    int myNumbers[10];
    for(int i =0; i < SIZE_ARRAY; i++)
    {
        myNumbers[i] = get_random();
    }
    selection_sort(myNumbers);
}

/* gets random number. seeded with time for randomness */
static int get_random()
{
    srand(time(NULL));

    // Generate a random number between 1 and 1000
    return ((rand() % 1000) + 1)
}

