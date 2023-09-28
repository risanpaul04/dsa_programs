#include<stdio.h>
int main(){
    int i, j, arr[10];

    printf("Input the elements of array: \n");

    for(int i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    printf("The given array is: \n");
    for(int i=0; i<10; i++){
        printf("%d  ", arr[i]);
    }

    printf("\n");
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The sorted array is: \n");
    for(int i=0; i<10; i++){
        printf("%d  ", arr[i]);
    }

    return 0;
}