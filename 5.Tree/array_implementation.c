#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the tree

int tree[MAX_SIZE];  // The array to hold the tree

// Function to insert a new element in the tree
void insert(int val, int index) {
    if(index < MAX_SIZE) {
        tree[index] = val;
    } else {
        printf("Tree is full. Cannot insert new element.\n");
    }
}

// Function to print the tree
void print_tree() {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(tree[i] != 0) {  // If the spot is not empty
            printf("Node at index %d: %d\n", i, tree[i]);
        }
    }
}

int main() {
    // Initialize the tree to be empty
    for(int i = 0; i < MAX_SIZE; i++) {
        tree[i] = 0;
    }

    // Insert some elements
    insert(1, 0);
    insert(2, 1);
    insert(3, 2);

    // Print the tree
    print_tree();

    return 0;
}