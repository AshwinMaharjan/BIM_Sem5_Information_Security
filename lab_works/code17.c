#include <stdio.h>
#include <math.h>

// Function to compute power mod (base^exp % mod)
int power_mod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to check if g is a primitive root modulo n
int is_primitive_root(int g, int n) {
    // Check if g^k % n != 1 for all k < n-1
    for (int i = 1; i < n; i++) {
        if (power_mod(g, i, n) == 1) {
            return 0; // g is not a primitive root
        }
    }
    return 1; // g is a primitive root
}

// Function to find and print all primitive roots of n
void find_primitive_roots(int n) {
    printf("Primitive roots of %d: ", n);
    
    // For numbers less than 2, there are no primitive roots
    if (n < 2) {
        printf("None\n");
        return;
    }

    // Loop through numbers from 1 to n-1 and check if they are primitive roots
    int found = 0;
    for (int g = 2; g < n; g++) {
        if (is_primitive_root(g, n)) {
            printf("%d ", g);
            found = 1;
        }
    }
    if (!found) {
        printf("None\n");
    }
    printf("\n");
}

int main() {
    int n;
    
	printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter a positive integer to find its primitive roots: ");
    scanf("%d", &n);
    
    find_primitive_roots(n);
    
    return 0;
}
