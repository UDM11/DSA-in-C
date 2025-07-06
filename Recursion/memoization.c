#include <stdio.h>
#include <time.h>

#define MAX 100
long long memo[MAX];

long long fibMemoization(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibMemoization(n - 1) + fibMemoization(n - 2);
    return memo[n];
}

int main() {
    int n = 45;
    clock_t start, end;
    
    for(int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }
    
    start = clock();
    printf("Memoized Fibonacci(%d) = %lld\n", n, fibMemoization(n));
    end = clock();
    printf("Time taken (memoized): %f seconds\n", 
           ((double)(end - start)) / CLOCKS_PER_SEC);
    
    return 0;
}