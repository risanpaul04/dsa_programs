#include<stdio.h>

int binarySearch(int arr[], int lower_bound, int upper_bound, int key)
{
    int beg, mid, end;
    beg = lower_bound;
    end = upper_bound;
    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n-1, key);
    if(result!=-1)
    {
        printf("Element %d is found at index %d", key, result);
    }
    else
    {
        printf("Element not found.");
    }

    return 0;
}