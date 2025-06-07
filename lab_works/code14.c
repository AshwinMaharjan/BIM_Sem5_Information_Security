#include <stdio.h>

// S1 Box from DES
int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

// Function to get S1 box output
int getS1Output(int input) {
    int row = ((input & 0x20) >> 4) | (input & 0x1); // First and last bit form the row
    int col = (input >> 1) & 0xF; // Middle four bits form the column
    return S1[row][col];
}

int main() {
    int input;
    
    // Taking a 6-bit input value
    printf("Ashwin Maharjan - 20790506\n\n");
    printf("Enter a 6-bit binary number (0-63): ");
    scanf("%d", &input);
    
    if (input < 0 || input > 63) {
        printf("Invalid input! Please enter a number between 0 and 63.\n");
        return 1;
    }
    
    int output = getS1Output(input);
    printf("S-Box (S1) Output: %d\n", output);
    
    return 0;
}