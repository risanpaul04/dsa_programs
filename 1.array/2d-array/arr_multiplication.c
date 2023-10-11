#include<stdio.h>

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

int main(){
    int r1, c1, r2, c2, i, j, k;

    printf("Enter no. of rows & columns in A matrix: ");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    printf("Enter the elements of B matrix: \n");
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

    int res[r1][c2];
    if(c1!=r2){
        printf("ERROR! Multiplication not possible!");
    }
    else{
        mat_multi(r1, c1, r2, c2, a, b, res);
        printf("The resultant matrix: \n");
        for(i=0; i<r1; i++){
            for(j=0; j<c2; j++){
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}