#include<stdio.h>
#define Max 100

void array_concatination(int s1, int s2,int a1[], int a2[], int res[s1+s2]){
    int i, index = 0;
    for(i=0; i<s1; i++){
        res[index] = a1[i];
        index++;
    }
    for(i=0; i<s2; i++){
        res[index] = a2[i];
        index++;
    }
}

int main(){
    int arr1[Max], arr2[Max], size1, size2, i,j;
    printf("Size of 1st array: ");
    scanf("%d", &size1);
    printf("Enter the elements of the 1st array: \n");
    for(i=0; i<size1; i++){
        scanf("%d", &arr1[i]);
    }

    printf("Size of 2nd array: ");
    scanf("%d", &size2);
    printf("Enter the elements of the 2nd array: \n");
    for(i=0; i<size2; i++){
        scanf("%d", &arr2[i]);
    }

    int size = size1 + size2;
    int cat_arr[size];
    array_concatination(size1, size2, arr1, arr2, cat_arr);

    printf("Array after concatination: \n");
    for(i=0; i<size; i++){
        printf("%d ", cat_arr[i]);
    }
    return 0;
}