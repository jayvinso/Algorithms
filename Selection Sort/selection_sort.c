/* Author: JAYDEN VINSON */

/* standard libraries */
#include <stdio.h>
#include <stdlib.h>

// user made files 
/* include the other header */
#include "test_driver.h"

/* include my own header file last*/
#include "selection_sort.h"

/* driver */
int main()
{
    user_prompt();
}

/* prompts the user for what they want to do. Inptu their own data or use my data */
void user_prompt()
{
    printf("What would you like to do\n");
    printf("1: input your own array to be sorted via SelectionSort\n2: Use the test drivers\n");

    int num;
    scanf("%i",&num);

    switch(num) {
        case 1: 
            return user_driven();
        default: 
            return run_tests();
    }
}

int user_driven()
{
    char input[1024];
    printf("Enter numbers separated by commas. EX) (1,2,3,4): ");
    //reads in inptu
    fgets(input, sizeof(input), stdin); 

    // count number of nums in input
    int count = 1; 
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ',') {
            count++;
        }
    }

    // dynamic memory since dynamic number of elements
    int *array = malloc(count * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Parse the input and store the numbers in the array
    int index = 0;
    char *token = strtok(input, ",");
    while (token != NULL) {
        array[index++] = atoi(token); 
        token = strtok(NULL, ",");
    }

    // Print the array before and after sorting 
    printf("\nYou entered the following array:\n");
    print_array(array,count);
    printf("\nAfter sorting\n");
    selection_sort(array,count);
    print_array(array,count);
    

    // Free the allocated memory
    free(array);

    return EXIT_SUCCESS;
}

/* prints out every element in the array */
int print_array(int *array,int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
}


/* pass in an array of ints to selection sort. */
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // Assume the current index is the smallest
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}



