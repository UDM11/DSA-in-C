#include <stdio.h>
#include <time.h>

// Regular recursive Fibonacci - O(2^n) time complexity
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative Fibonacci - O(n) time complexity
int fibIterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 30;
    clock_t start, end;
    
    // Measure recursive approach
    start = clock();
    printf("Recursive Fibonacci(%d) = %d\n", n, fibRecursive(n));
    end = clock();
    printf("Time taken (recursive): %f seconds\n", 
           ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Measure iterative approach
    start = clock();
    printf("Iterative Fibonacci(%d) = %d\n", n, fibIterative(n));
    end = clock();
    printf("Time taken (iterative): %f seconds\n", 
           ((double)(end - start)) / CLOCKS_PER_SEC);
    
    return 0;
}