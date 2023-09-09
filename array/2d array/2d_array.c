#include<stdio.h>
#include<stdlib.h>

void create(int row, int col, int mat[row][col]);

void display(int row, int col, int arr[row][col]);

void mat_add(int r1, int c1, int a1[r1][c1], int a2[r1][c1], int res[r1][c1]);

void mat_sub(int row, int col, int a1[row][col], int a2[row][col], int res[row][col]);

void mat_multi(int r1, int c1, int r2, int c2, int a1[r1][c1], int a2[r2][c2], int res[r1][c2]);

int main()
{
    int r1, c1, r2, c2, i, j, k;
    int choice = -1, flag=1;

    // Menu display
    printf("MENU:\n1. Matrix Addition\n2. Matrix Subtraction\n3. Matrix Multiplication\n4. Matrix transpose\n5. Exit");
    
    // Infinite Loop for choice input
    while(flag){
        printf("\nEnter the operation you wish to perform:");
        scanf("%d", &choice);

        if(choice==4){
             printf("Enter no. of rows & columns in the matrix: ");
            scanf("%d %d", &r1, &c1);
            int a[r1][c1];
            printf("Enter the elements of the matrix: \n");
            create(r1, c1, a);
        }
        else if(choice!=5)
        {
            printf("Enter no. of rows & columns in A matrix: ");
            scanf("%d %d", &r1, &c1);
            int a[r1][c1];
            printf("Enter the elements of A matrix: \n");
            create(r1, c1, a);

            printf("Enter no. of rows & columns in B matrix: ");
            scanf("%d %d", &r2, &c2);
            int b[r2][c2];
            printf("Enter the elements of B matrix: \n");
            create(r2, c2, b);
        }
    
        
        
        
        // If-else ladder
        if(choice == 1){
            if(r1!=r2 && c1 != c2)
            {
                printf("Matrix addition not possible !");
            }
            else
            {
                int res_add[r1][c1];
                mat_add(r1, c1, a, b, res_add);
                printf("\nResultant matrix: \n");
                display(r1, c1, res_add);
            }
            
        }
        else if (choice == 2){
            mat_sub();
            printf("\nResultant matrix: \n");
            display(r1, c1, res);
        }
        else if (choice == 3){
            mat_multi();
            printf("\nResultant matrix: \n");
            display(r1, c2, res);
        }
        else if (choice == 4){
            mat_trarspose();
            printf("\nResultant matrix: \n");
            display(r1, c1, res);
        }
        else if (choice == 5){
            printf("BYE!!!\n");
            flag = 0;
        }
        else{
            printf("> Invalid Input\n");
        }
    }
    return 0;
}

void create(int row, int col, int mat[row][col])
{
    int i, j, inarr[row][col];
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