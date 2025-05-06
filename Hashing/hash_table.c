/* Author: Jayden Vinson */

/* standard import */
#include <stdlib.h>
#include <stdio.h>

/* my own header file*/
#include "hash_table.h"

/* prints out every node in the linked list. this should only be called as a function pointer */
static void print_linked_list_node(Node *n)
{
    printf("Data-> %i",n->data);
}

/* frees a node in the linked list. */
static void free_node(Node *n)
{
    free(n);
}

/* goes through a linked list and applies the helper function */
static void go_through_linkedlist(void (*fp)(Node *n),Node *header)
{
    Node *holder;
    while(header != NULL)
    {
        holder = header->next;
        fp(header);
        header=holder;
    }
}

/* gets a new node for the user to use. */
static Node *make_node()
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        printf("Allocation failure\n");
        exit(1);
    } 
    return newNode;
}

/* implements true mod (% is remainder operator)*/
static int true_mod(int numToHash, int numBuckets)
{
    return (numToHash % numBuckets + numBuckets) % numBuckets;
}

/* prints an individual bucket out */
static void print_bucket(int bucket,void *array)
{
    go_through_linkedlist(print_linked_list_node,array);
}

/* prints the entire hashmap */
void print_hashmap(void *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Bucket %i: ",i);
        print_bucket(i,array);
    }
}

/* returns a hashap for the user to use. */
void *create_hashmap(int numBuckets)
{
    Node **array = (Node **)calloc(numBuckets, sizeof(Node *));
    if (!array) 
    {
        printf("Allocation failure\n");
        exit(1);
    }
    return array;
}

/* add a data point (int) to hashmap. */
int add_to_hashmap(void *array,int data,int size)
{
    Node **HashMap = array;
    Node *newNode = make_node();

    newNode->data = data;
    int loco = true_mod(data,size);

    if (HashMap[loco] == NULL) 
    {
    HashMap[loco] = newNode;
    } 
    else 
    {
    Node *current = HashMap[loco];
    while (current->next != NULL) 
    {
        if(current->data == data) 
        {
            free(newNode);
            printf("Dont put duplicates values into the HashMap");
            return EXIT_FAILURE;
        } 
        current = current->next;
    }
    current->next = newNode;
    }
    return EXIT_SUCCESS;
}

/* delete an item from the hashmap. */
void delete_from_hashmap(void *array, int data, int size) {
    Node **HashMap = (Node **)array;
    int loco = true_mod(data, size);

    Node *current = HashMap[loco];
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                // Deleting the head node
                HashMap[loco] = current->next;
            } else {
                // Bypass the current node
                prev->next = current->next;
            }
            free(current);
            printf("Data %i deleted from bucket %i.\n", data, loco);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Data %i not found in bucket %i.\n", data, loco);
} 

void free_memory(void *arr,int size)
{
    Node **HashMap = arr;
    for(int i = 0; i < size; i++)
    {
        if(HashMap[i])
        {
            go_through_linkedlist(free_node,HashMap[i]);
        }
    }
}
