#include<stdio.h>

#define N 20

int stack[N];
int top = -1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(top==N-1){
        return 1;
    }
    return 0;
}

void push(int val){
    if(isFull()){
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = val;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack empty\n");
    }
    else{
        int item = stack[top];
        printf("Popped from top: %d\n", item);
        top--;
    }
}

void peek(){
    printf("Top: %d\n", stack[top]);
}

void display(){
    int i = top;
    printf("Stack: ");
    while(i>=0){
        printf("%d ", stack[i]);
        i--;
    }
}

int main() {
    // push(20);
    // push(10);
    // push(50);
    // peek();
    pop();
    push(90);
    display();

    return 0;
}