#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        char letter = plaintext[i];

        if (isalpha(letter)) {
            char base = isupper(letter) ? 'A' : 'a';
            char keyBase = isupper(key[j]) ? 'A' : 'a';
            ciphertext[i] = ((letter - base + (key[j] - keyBase)) % 26) + base;
            j = (j + 1) % keyLen;
        } else {
            ciphertext[i] = letter;
        }
    }
    ciphertext[textLen] = '\0';
}

void decryptVigenere(char *ciphertext, char *key, char *decryptedText) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        char letter = ciphertext[i];

        if (isalpha(letter)) {
            char base = isupper(letter) ? 'A' : 'a';
            char keyBase = isupper(key[j]) ? 'A' : 'a';
            decryptedText[i] = ((letter - base - (key[j] - keyBase) + 26) % 26) + base;
            j = (j + 1) % keyLen;
        } else {
            decryptedText[i] = letter;
        }
    }
    decryptedText[textLen] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decryptedText[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%s", key);

    encryptVigenere(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    decryptVigenere(ciphertext, key, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}
