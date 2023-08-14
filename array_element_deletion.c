#include<stdio.h>

int main(){
    int pos, arr[5];

    //Taking input for array elements
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }

    //Showing the original array
    printf("The array elements before deletion: \n");
    for(int i=0; i<5; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");

    //Taking input for the position to be deleted
    printf("Enter the position of the element to be deleted: \n");
    scanf("%d", &pos);

    for(int i=pos-1; i<5-1; i++){
        arr[i]=arr[i+1];
    }

    //Output after element deletion
    printf("The array elements after deletion: \n");
    for(int i=0; i<5; i++){
        printf("%d  ", arr[i]);
    }
    return 0;
}