#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100  // Fixed size for stack and input string

// Stack structure for characters
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

// Initialize the stack
void initialize(CharStack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(CharStack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push character to stack
void push(CharStack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
    } else {
        s->data[++(s->top)] = c;
    }
}

// Pop character from stack
char pop(CharStack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        return s->data[(s->top)--];
    }
}

// Reverse the string using stack
void reverseString(char str[]) {
    CharStack stack;
    initialize(&stack);

    // Push all characters onto stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop characters to reverse the string
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character if any

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
