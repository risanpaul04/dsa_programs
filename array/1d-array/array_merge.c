#include<stdio.h>

void create(int n, int arr[n])
{
    printf("enter the element of the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void display(int n, int arr[n])
{
    int i;
    printf("\n[ ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");

}

void merge()
{
    
}

int main()
{
    int i, j, r1, r2;

    printf("No. of elements in the 1st array: ");
    scanf("%d", &r1);
    int arr1[r1];
    create(r1, arr1);
    display(r1, arr1);

    printf("No. of elements in the 2nd array: ");
    scanf("%d", &r2);
    int arr2[r2];
    create(r2, arr2);
    display(r2, arr2);

    int r = r1 +r2;
    int merge_arr[r];
    merge();


    return 0;
}