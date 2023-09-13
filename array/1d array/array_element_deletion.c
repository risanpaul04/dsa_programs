#include<stdio.h>

void array_deletion(int arr[], int size, int pos){
    for(int i=pos-1; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    
}

int main(){
    int size, pos, arr[50];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    //Taking input for array elements
    printf("Enter the elements of the array: \n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    //Showing the original array
    printf("The array elements before deletion: \n");
    for(int i=0; i<size; i++){
        printf("%d  ", arr[i]);
    }

    //Taking input for the position to be deleted
    printf("\nEnter the position of the element to be deleted: \n");
    scanf("%d", &pos);

    if(pos<=0 || pos>size){
        printf("Invalid position!");
    }
    else{
        array_deletion(arr, size, pos);
        size--;
        //Output after element deletion
        printf("The array elements after deletion: \n");
        for(int i=0; i<size; i++){
            printf("%d  ", arr[i]);
        }
    }
    return 0;
}