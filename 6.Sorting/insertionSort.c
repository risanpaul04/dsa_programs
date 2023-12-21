#include <stdio.h>

int main()
{
    int n, i, j, current;
    printf("No. of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    for (i=0; i<n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The given array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Insertion sort
    for (i = 1; i < n; i++)
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current;
    }

    printf("\nArray after insertionSort: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}