#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform modular exponentiation (base^exp % mod)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Rabin-Miller Primality Test
int is_prime(long long n, int k) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;

    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Perform k iterations of the test
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = power_mod(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        int composite = 1;
        for (int j = 0; j < r - 1; j++) {
            x = power_mod(x, 2, n);
            if (x == n - 1) {
                composite = 0;
                break;
            }
        }

        if (composite) return 0;
    }
    return 1;
}

int main() {
    long long n;
    int k = 5; // Number of iterations for accuracy

    printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter a number to check if it's prime: ");
    scanf("%lld", &n);

    if (is_prime(n, k))
        printf("%lld is probably prime.\n", n);
    else
        printf("%lld is composite.\n", n);

    return 0;
}