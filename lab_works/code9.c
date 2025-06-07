#include <stdio.h>
 

// Function to compute the Extended Euclidean Algorithm
int extended_gcd(int a, int b, int *x, int *y) {
    int x1, y1;
    int q, r;
    int old_x = 1, old_y = 0;
    int current_x = 0, current_y = 1;
 

    printf("%-10s %-10s %-10s %-10s %-10s\n", "q", "r", "x", "y", "gcd");
    while (b != 0) {
        q = a / b;
        r = a % b;
 

        x1 = old_x - q * current_x;
        y1 = old_y - q * current_y;
 

        printf("%-10d %-10d %-10d %-10d %-10d\n", q, r, current_x, current_y, b);
 

        old_x = current_x;
        old_y = current_y;
        current_x = x1;
        current_y = y1;
 

        a = b;
        b = r;
    }
 

    *x = old_x;
    *y = old_y;
    return a;
}

 

int main() {
    int num1, num2, x, y;
 

    printf("\n\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
     
    int gcd = extended_gcd(num1, num2, &x, &y);
    printf("\nGCD of the given numbers is: %d\n", gcd);
    printf("Coefficient: x = %d, y = %d\n", x, y);
 

    return 0;
}