#include<stdio.h>

int main(){
    int arr[100], size, pos, key, i;
    //taking size & elements of array
    printf("Enter size of array: ");
    scanf("%d", &size);
    // Taking array element
    printf("Enter array elements: \n");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    //array before insertion
    printf("Array before insertion: \n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    //taking key and position
    printf("\nEnter data you want to insert: ");
    scanf("%d", &key);
    printf("Enter position: ");
    scanf("%d", &pos);
    //insertion algo
    if(pos<=0 || pos>size+1){
        printf("Invalid position! Insertion not possible!");
    }
    else{
        for(i=size-1; i>=pos-1; i--){
            arr[i+1] = arr[i];
        }
        arr[pos-1] = key;
        size++;
    }
    
    //array after insertion
    printf("Array after insertion:\n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}