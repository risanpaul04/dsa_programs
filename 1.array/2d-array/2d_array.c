#include<stdio.h>
#include<stdlib.h>

void create(int row, int col, int mat[row][col])
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("el[%d][%d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
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

void mat_add(int r1, int c1, int a1[r1][c1], int a2[r1][c1], int res[r1][c1])
{
    int i, j;
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            res[i][j] = a1[i][j] + a2[i][j];
        }
    }
}

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

void mat_multi(int r1, int c1, int r2, int c2, int a1[r1][c1], int a2[r2][c2], int res[r1][c2])
{
    int i, j, k;
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            res[i][j] = 0;
            for(k=0; k<c1; k++){
                res[i][j] = res[i][j] + a1[i][k]*a2[k][j];
            }
        }
    }  
}

void mat_transpose(int row, int col, int arr[row][col], int tr_arr[col][row])
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            tr_arr[j][i] = arr[i][j];
        }
    }
}


int main()
{
    int r1, c1, r2, c2, i, j, k;

    int a[100][100];
    int b[100][100];

    int choice;
    int flag = 1;
    
    // Infinite Loop for choice input
    while(flag)
    {
        // Menu display
        printf("\n\t\t\tMENU:\n1. Matrix Addition\t\t2. Matrix Subtraction\n3. Matrix Multiplication\t4. Matrix transpose\n5. Exit\n");
        
        printf("\nEnter the operation you wish to perform:");
        scanf("%d", &choice);

        if(choice==4){
            printf("Enter no. of rows & columns in the matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter the elements of the matrix: \n");
            create(r1, c1, a);
            printf("\nThe given matrix:\n");
            display(r1, c1, a);

            int res_transpose[c1][r1];
            mat_transpose(r1, c1, a, res_transpose);
            printf("\nResultant matrix: \n");
            display(c1, r1, res_transpose);
        }
        else if(choice!=5)
        {
            printf("Enter no. of rows & columns in A matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter the elements of A matrix: \n");
            create(r1, c1, a);

            printf("Enter no. of rows & columns in B matrix: ");
            scanf("%d %d", &r2, &c2);
            printf("Enter the elements of B matrix: \n");
            create(r2, c2, b);

            printf("\nThe first matrix:\n");
            display(r1, c1, a);

            printf("\nThe 2nd matrix:\n");
            display(r2, c2, b);

            switch (choice)
            {
                case 1:
                    if(r1!=r2 || c1 != c2)
                    {
                        printf("\nMatrix addition not possible !");
                    }
                    else
                    {
                      int res_add[r1][c1];
                        mat_add(r1, c1, a, b, res_add);
                        printf("\nResultant matrix: \n");
                        display(r1, c1, res_add);
                    }
                    break;

                case 2:
                    if(r1!=r2 || c1 != c2)
                    {
                        printf("Matrix Subtraction not possible !");
                    }
                    else
                    {
                        int res_sub[r1][c1];
                        mat_sub(r1, c1, a, b, res_sub);
                        printf("\nResultant matrix: \n");
                        display(r1, c1, res_sub);
                    }
                    break;

                case 3:
                    if(c1!=r2)
                    {
                        printf("\nMatrix multiplication not possible !");
                    }
                    else
                    {
                        int res_multi[r1][c1];
                        mat_multi(r1, c1, r2, c2, a, b, res_multi);
                        printf("\nResultant matrix: \n");
                        display(r1, c2, res_multi);
                    }
                    break;
                default:
                    printf("> Invalid Input\n");
                    break;
            }

        }
        else
        {
            printf("\n\tGoodbye ! Happy coding :)\n");
            flag = 0;
        }
    }
    return 0;
}