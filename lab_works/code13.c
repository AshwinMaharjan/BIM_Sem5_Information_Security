#include <stdio.h>
#include <string.h>

#define MOD 26

// Function to compute determinant of a 2x2 matrix
int determinant(int key[2][2]) {
    return (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
}

// Function to find modular inverse of a number under mod 26
int modInverse(int num) {
    num = (num % MOD + MOD) % MOD;
    for (int i = 1; i < MOD; i++) {
        if ((num * i) % MOD == 1) {
            return i;
        }
    }
    return -1;
}

// Function to compute inverse of 2x2 key matrix
void inverseKeyMatrix(int key[2][2], int invKey[2][2]) {
    int det = determinant(key);
    int detInv = modInverse(det);
    
    if (detInv == -1) {
        printf("Modular inverse does not exist. Decryption not possible.\n");
        return;
    }
    
    invKey[0][0] = ( key[1][1] * detInv) % MOD;
    invKey[0][1] = (-key[0][1] * detInv) % MOD;
    invKey[1][0] = (-key[1][0] * detInv) % MOD;
    invKey[1][1] = ( key[0][0] * detInv) % MOD;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (invKey[i][j] < 0) {
                invKey[i][j] += MOD;
            }
        }
    }
}

// Function to encrypt the plaintext using Hill Cipher
void encrypt(int key[2][2], char plaintext[3], char ciphertext[3]) {
    int pt[2];
    pt[0] = plaintext[0] - 'A';
    pt[1] = plaintext[1] - 'A';
    
    int ct[2];
    ct[0] = (key[0][0] * pt[0] + key[0][1] * pt[1]) % MOD;
    ct[1] = (key[1][0] * pt[0] + key[1][1] * pt[1]) % MOD;
    
    ciphertext[0] = ct[0] + 'A';
    ciphertext[1] = ct[1] + 'A';
    ciphertext[2] = '\0';
}

// Function to decrypt the ciphertext using Hill Cipher
void decrypt(int key[2][2], char ciphertext[3], char decrypted[3]) {
    int invKey[2][2];
    inverseKeyMatrix(key, invKey);
    
    int ct[2];
    ct[0] = ciphertext[0] - 'A';
    ct[1] = ciphertext[1] - 'A';
    
    int pt[2];
    pt[0] = (invKey[0][0] * ct[0] + invKey[0][1] * ct[1]) % MOD;
    pt[1] = (invKey[1][0] * ct[0] + invKey[1][1] * ct[1]) % MOD;
    
    decrypted[0] = pt[0] + 'A';
    decrypted[1] = pt[1] + 'A';
    decrypted[2] = '\0';
}

int main() {
    int key[2][2];
    char plaintext[3], ciphertext[3], decrypted[3];
    
    // Taking key matrix input
    printf("Ashwin Maharjan - 20790506\n\n");
	printf("Enter 2x2 key matrix (mod 26 values):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }
    
    // Taking plaintext input (2 characters)
    printf("Enter a two-letter plaintext (uppercase only): ");
    scanf("%s", plaintext);
    
    encrypt(key, plaintext, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    
    decrypt(key, ciphertext, decrypted);
    printf("Decrypted text: %s\n", decrypted);
    
    return 0;
}
