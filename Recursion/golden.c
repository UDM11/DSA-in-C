#include <stdio.h>
int main() {
    double a = 1, b = 1, c;
    printf("Ratio of consecutive Fibonacci numbers:\n");
    for(int i = 0; i < 20; i++) {
        c = a + b;
        printf("F(%d)/F(%d) = %.10f\n", i+2, i+1, c/b);
        a = b;
        b = c;
    }
    printf("\nActual Golden Ratio (φ) = 1.6180339887\n");
    return 0;
}



