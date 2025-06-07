#include <stdio.h>
#include <math.h>

// Function to calculate gcd
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular inverse of e under modulo phi(n)
long long mod_inverse(long long e, long long phi) {
    long long t = 0, new_t = 1;
    long long r = phi, new_r = e;
    long long q, temp_t, temp_r;

    while (new_r != 0) {
        q = r / new_r;

        // Update t
        temp_t = new_t;
        new_t = t - q * new_t;
        t = temp_t;

        // Update r
        temp_r = new_r;
        new_r = r - q * new_r;
        r = temp_r;
    }

    // If gcd(e, phi) != 1, no modular inverse exists
    if (r > 1)
        return -1;

    // Ensure result is positive
    if (t < 0)
        t += phi;

    return t;
}

// Function to perform modular exponentiation (base^exp % mod)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// RSA Key Generation and Encryption/Decryption
void rsa() {
    long long p, q, n, phi, e, d, message, encrypted, decrypted;

    // Step 1: Input two prime numbers p and q
    printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter prime number q: ");
    scanf("%lld", &q);

    // Step 2: Calculate n = p * q and phi = (p-1)*(q-1)
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Step 3: Choose public key exponent e (e should be coprime with phi)
    printf("Enter public key exponent e (1 < e < phi): ");
    scanf("%lld", &e);

    // Check if e and phi(n) are coprime
    while (gcd(e, phi) != 1) {
        printf("e and phi(n) are not coprime. Enter a different e: ");
        scanf("%lld", &e);
    }

    // Step 4: Calculate the private key exponent d (d * e % phi = 1)
    d = mod_inverse(e, phi);
    
    // Ensure a valid modular inverse exists
    if (d == -1) {
        printf("Error: Modular inverse of e does not exist. Choose a different e.\n");
        return;
    }

    printf("Public key: (e = %lld, n = %lld)\n", e, n);
    printf("Private key: (d = %lld, n = %lld)\n", d, n);

    // Step 5: Input message to encrypt
    printf("Enter a message (as a number less than n): ");
    scanf("%lld", &message);

    if (message >= n) {
        printf("Error: Message must be less than n.\n");
        return;
    }

    // Step 6: Encrypt the message
    encrypted = power_mod(message, e, n);
    printf("Encrypted message: %lld\n", encrypted);

    // Step 7: Decrypt the message
    decrypted = power_mod(encrypted, d, n);
    printf("Decrypted message: %lld\n", decrypted);
}

int main() {
    rsa();
    return 0;
}
