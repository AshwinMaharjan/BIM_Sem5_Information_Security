#include <stdio.h>

// Function to implement Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}

// Function to find the modular inverse
int modularInverse(int a, int n) {
    int x, y;
    int gcd = extendedEuclidean(a, n, &x, &y);
    
    // Inverse exists only if gcd(a, n) = 1
    if (gcd != 1) {
        printf("Modular inverse does not exist.\n");
        return -1;
    } else {
        // Ensure positive result
        return (x % n + n) % n;
    }
}

int main() {
    int a, n;
    
    // Taking input from user
    printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter a number and modulo n: ");
    scanf("%d %d", &a, &n);
    
    int inverse = modularInverse(a, n);
    
    if (inverse != -1) {
        printf("Modular inverse of %d modulo %d is: %d\n", a, n, inverse);
    }
    
    return 0;
}
