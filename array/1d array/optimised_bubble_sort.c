#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Input the elements of array: \n");

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("The given array is: \n");
    for(int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, n);

    printf("\nThe sorted array is: \n");
    for(int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
    return 0;
}