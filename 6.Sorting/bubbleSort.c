#include <stdio.h>
#include <stdlib.h>

void createArray(int n, int* arr) {
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int n, int* arr) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on the array
void bubbleSort(int n, int* arr) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* Arr = (int*)malloc(n * sizeof(int));
    createArray(n, Arr);

    printf("The given array: ");
    displayArray(n, Arr);

    bubbleSort(n, Arr);
    printf("Array after sorting: ");
    displayArray(n, Arr);

    // Don't forget to free the allocated memory
    free(Arr);

    return 0;
}