#include<stdio.h>

int main()
{
    int arr[5] = {3, 5, 2, 12, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The given array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Code for insertion sort

    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>current)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    // Code for Selection sort

    

    printf("Array after sorting: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}