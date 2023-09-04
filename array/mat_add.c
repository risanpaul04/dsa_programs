#include<stdio.h>

void arr_input(int* row, int* col, int* arr[][]){
    int i, j;
    printf("Enter size of the array: ");
    scanf("%d %d",&row, &col);
    int arr[*row][*col];
    printf("Enter the elements of the array: \n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

int main(){
    int r1=3, r2, c1=3, c2, arr1[r1][c1], arr2[r2][c2], res[r1][c1], i, j;
    arr_input(&r1, &c1, &arr1);
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("%d ", arr1[i][j]);
        }
    }
    return 0;
}