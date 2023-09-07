#include<stdio.h>

void create(int row, int col, int mat[row][col]){
    int i, j, inarr[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("el[%d][%d]: ", i+1, j+1);
            scanf("%d", &inarr[i][j]);
            mat[i][j] = inarr[i][j];
        }
    }
}

void display(int row, int col, int arr[row][col])
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r1, c1, r2, c2, i, j, k;

    printf("Enter no. of rows & columns in A matrix: ");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    printf("Enter the elements of B matrix: \n");

    create(r1, c1, a);
    printf("\n the matrix: \n");
    display(r1, c1, a);

    return 0;
}