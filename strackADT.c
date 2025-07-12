#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];
int top = -1;

void push(int data){
    if(top == MAX_SIZE -1)
    {
        printf("Stack Overflow! Cannot Push %d. \n", data);
    }
    else{
        top++;
        stack[top] = data;
        printf("%d pushed to stack. \n", data);
    }
}

void pop(){
    if(top == -1)
    {
        printf("Stack Underflow! Cannot Pop \n");
    }
    else{
        int popped_data = stack[top];
        top--;
        printf("%d popped from stack. \n", popped_data);
    }
}

bool isFull(){
    return top == -1;
}

void display(){
    if(top == -1)
    {
        printf("Stack is empty. NOthing to display. \n");
    }
    else{
        printf("Elements in stack:");
        for(int i=top; i>=0; i--){
            printf("%d \t", stack[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(top == -1)
    {
        printf("Stack is empty. NOthing to peek. \n");
    }
    else{
        printf("Top element is %d. \n", stack[top]);
    }
}

int main(){
    printf("---STACK OPERATIONS IN C---\n");

    push(10);
    push(20);
    push(30);

    display();
    peek();

    push(40);
    push(50);
    push(60);

    display();
    peek();

    pop();
    display();
    peek();

    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}