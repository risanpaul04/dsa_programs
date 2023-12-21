#include<stdio.h>

int main()
{
    int n, i, j;
    printf("No. of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for(i=0; i<n; i++)
    {
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The given array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    // code of selection sort
    for(i=0; i<n-1; i++)
    {
        int min = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min])
            {
                min = j;
            }
            if(min!=i){
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            } 
        }
    }

    printf("\nThe array after selection sort: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

}