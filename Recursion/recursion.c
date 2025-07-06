#include <stdio.h>

void directRecursion(int n) {
    if (n == 0) return;
    printf("%d ", n);
    directRecursion(n - 1);
}

// Indirect Recursion
void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        printf("%d ", n);
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 1) {
        printf("%d ", n);
        functionA(n / 2);
    }
}

// Linear Recursion
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Tail Recursion
void tailRecursion(int n, int acc) {
    if (n == 0) {
        printf("Result: %d\n", acc);
        return;
    }
    tailRecursion(n - 1, acc + n);
}

int main() {
    printf("Direct Recursion: ");
    directRecursion(5);
    printf("\n\nIndirect Recursion: ");
    functionA(10);
    printf("\n\nFactorial (Linear Recursion) of 5: %d", factorial(5));
    printf("\n\nTail Recursion Sum 1 to 5: ");
    tailRecursion(5, 0);
    return 0;
}