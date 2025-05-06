/* Author: Jayden Vinson. */

typedef struct Node {
    struct Node *next;
    int data;
} Node;

/* Function declarations */
void print_linked_list_node(Node *n);
void go_through_linkedlist(void (*fp)(Node *n), Node *header);
Node *make_node();
int true_mod(int numToHash, int numBuckets);
void print_bucket(int bucket, void *array);
void print_hashmap(void *array, int size);
void *create_hashmap(int numBuckets);
int add_to_hashmap(void *array, int data, int size);
void delete_from_hashmap(void *array, int data, int size);
void free_memory(void *arr,int size);