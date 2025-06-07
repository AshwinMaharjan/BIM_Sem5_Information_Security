#include <stdio.h>
#include <ctype.h>

int main() {
    char text[500], ch;
    int key;

    // Taking user input
    printf("\n\nEnter a message to encrypt: ");
    fgets(text, sizeof(text), stdin); // Accepts spaces

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypting
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalnum(ch)) {
            // Lowercase letter
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            // Uppercase letter
            else if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
            // Digit
            else if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
            // Replace original character
            text[i] = ch;
        }
        // Keep non-alphanumeric characters unchanged
    }

    printf("Encrypted message: %s\n", text);
    return 0;
}
