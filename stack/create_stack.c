//         -------  Creating stack using array  -------

#include<stdio.h>
#define N 10

int stack[N];
int top = -1;

void push()  // time complexity = O(1)
{
    int x;
    printf("enter data: ");
    scanf("%d", &x);

    if(top==N-1)
    {
        printf("Overflow !\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()  // time complexity = O(1)
{
    int item;
    if(top==-1)
    {
        printf("Underflow !\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("popped from top: %d\n", item);
    }
}

void peek()  // time complexity = O(1)
{
    if(top==-1)
    {
        printf("Stack empty");
    }
    else
    {
        printf("top = %d\n", stack[top]);
    }
}

void display() // time complexity = O(n)
{
    printf("given stack:\n");

    for(int i=top; i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
}


int main()
{
    int choice, flag=1;
    while(flag)
    {
        printf("\n\n\t\tStack\n");
        printf("\nMenu:\n1.push\n2.pop\n3.peek\n4.display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            flag = 0;
            printf("exiting program !");
            break;
        default:
            printf("\nIndalid input.\nchoose a valid option");
            break;
        }
    }

    return 0;
}