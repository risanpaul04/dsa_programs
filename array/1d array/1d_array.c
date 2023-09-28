#include<stdio.h>

void create(int n, int arr[n])
{
    
}

void array_deletion(int arr[], int size, int pos){
    for(int i=pos-1; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_reversal(int a[], int n){
    int s=0, e=n-1;
    while(s<e){
        swap(&a[s], &a[e]);
        s++;
        e--;
    }
}

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void array_concatination(int s1, int s2,int a1[s1], int a2[s2], int res[s1+s2]){
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
    int flag = 1;
    int choice;
    printf("\n\n\t\t1D ARRAY\n");

    //Choices
    while(flag){
        printf("Choose any operation from the list below: \n");
        printf("\n1. Array traversal");
        printf("\n2. Array element search");
        printf("\n3. Array element insertion");
        printf("\n4. Array element deletion");
        printf("\n5. Array concatination");
        printf("\n6. Exit !\n\n");
        printf("Your choice:  ");
        scanf("%d", &choice);

        switch(choice){
            case '1':
                // arr_traversal();
                break;
            case '2':
                // arr_search();
                break;
            case '3':
                // arr_insertion();
                break;
            case '4':
                // arr_deletion();
                break;
            case '5':
                // arr_concat();
                break;
            case '6':
                printf("Exiting Program.\nHappy Coding !");
                flag = 0;
                break;
            default:
                printf("> Invalid input. Choose any number from the Menu...");
                break;
        }
        printf("\n");
    }
    

    return 0;    
}