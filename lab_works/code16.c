#include <stdio.h>

// Function to compute Euler's Totient Function
int euler_totient(int n) {
    int result = n;  // Start with result as n
    
    // Iterate through all numbers from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        // Check if i is a divisor of n
        if (n % i == 0) {
            // If yes, it is a prime factor, so update result
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    
    // If n is still greater than 1, it means n itself is prime
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

int main() {
    int n;
	
	printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        int totient = euler_totient(n);
        printf("Euler's Totient value of %d is: %d\n", n, totient);
    }
    
    return 0;
}
