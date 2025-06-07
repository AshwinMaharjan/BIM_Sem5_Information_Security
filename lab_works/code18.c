#include <stdio.h>
#include <math.h>

// Function to perform modular exponentiation (base^exp % mod)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // In case base is larger than mod
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, a, b, A, B, shared_secret_A, shared_secret_B;

    // Step 1: Publicly known prime number p and base g
    printf("Ashwin Maharjan - 20790506\n\n");
	printf("Enter a prime number p: ");
    scanf("%lld", &p);
    printf("Enter a base g: ");
    scanf("%lld", &g);

    // Step 2: Generate private keys for both parties
    printf("Enter private key for Party A (a): ");
    scanf("%lld", &a);
    printf("Enter private key for Party B (b): ");
    scanf("%lld", &b);

    // Step 3: Compute public keys A and B
    A = power_mod(g, a, p);  // A = g^a mod p
    B = power_mod(g, b, p);  // B = g^b mod p

    // Step 4: Exchange the public keys (A and B)
    printf("Public key A for Party A: %lld\n", A);
    printf("Public key B for Party B: %lld\n", B);

    // Step 5: Compute the shared secret key for both parties
    shared_secret_A = power_mod(B, a, p);  // Party A computes K = B^a mod p
    shared_secret_B = power_mod(A, b, p);  // Party B computes K = A^b mod p

    // Step 6: Both shared secret keys should be the same
    printf("Shared secret key computed by Party A: %lld\n", shared_secret_A);
    printf("Shared secret key computed by Party B: %lld\n", shared_secret_B);

    // Step 7: Verify if the keys are same
    if (shared_secret_A == shared_secret_B) {
        printf("The shared secret key is successfully established: %lld\n", shared_secret_A);
    } else {
        printf("There was an error in key exchange.\n");
    }

    return 0;
}
