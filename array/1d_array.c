#include<stdio.h>



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