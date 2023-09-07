#include<stdio.h>

void mat_sub(int row, int col, int a1[row][col], int a2[row][col], int res[row][col])
{
    int i, j;
    for (i=0; i<row; i++)
    {
        for(j=0; j<col; j++){
            res[i][j] = a1[i][j] - a2[i][j];
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
    printf("Enter the elements of A matrix: \n");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("A%d%d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter no. of rows & columns in B matrix: ");
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];
    printf("Enter the elements of B matrix: \n");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            printf("B%d%d : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    int res[r1][c1];

    if(r1==r2 && c1==c2)
    {
        mat_sub(r1, c1, a, b, res);
        printf("The resultant matrix: \n");
        display(r1, c1, res);
    }
    else
    {
        printf("Matrix addition not possible !");
    }

}