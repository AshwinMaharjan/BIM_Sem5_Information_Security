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

int main() {
    int a, b, x, y;
    
    // Taking input from user
    printf("Ashwin Maharjan - 20790506\n\n");
	printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    int gcd = extendedEuclidean(a, b, &x, &y);
    
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    printf("Coefficients x = %d, y = %d\n", x, y);
    
    return 0;
}