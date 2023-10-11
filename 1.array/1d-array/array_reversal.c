#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_reversal(int a[], int n){
    int s=0, e=n-1;
    while(s<e){
        swap(&a[s], &a[e]);
        s++;
        e--;
    }
}

int main(){
    int arr[100], size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elemnents of the array: \n");
    for(i=0; i<size; i++){
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
    array_reversal(arr, size);
    printf("Array after reversal: \n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}