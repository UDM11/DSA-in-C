#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  // Fixed size of the stack

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push operation
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->data[s->top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}

// Pop operation
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;  // Return -1 for error
    } else {
        int popped = s->data[s->top];
        s->top--;
        return popped;
    }
}

// Peek operation
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}
// Main function to demonstrate stack operations
int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));

    return 0;
}
