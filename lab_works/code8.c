#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 5
 
 
char keyMatrix[SIZE][SIZE];

void prepareKeyMatrix(char key[]){
	int map[26] = {0};
	int i,j,k=0,len=strlen(key);
	char newKey[26] = {0};
	
	for(i=0;i<len;i++){
		if(key[i]=='j') key[i]='i';
		if(!map[key[i] - 'a']){
			newKey[k++] = key[i];
			map[key[i] - 'a'] = 1;
		}
	}
	
	for(i=0; i<26;i++){
		if(i+'a'!='j' && !map[i]){
			newKey[k++] = i + 'a';
		}
	}
	
	k=0;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			keyMatrix[i][j]=newKey[k++];
		}
	}
}


void findPosition(char ch, int *row, int *col){
	int i,j;
	if(ch =='j') ch='i';
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(keyMatrix[i][j] == ch){
				*row=i;
				*col=j;
				return;
			}
		}
	}
}

void prepareText(char text[], char processedText[]){
	int len = strlen(text), i, j=0;
	for(i=0;i<len;i++){
		if(text[i]=='j') text[i]='i';
		if(isalpha(text[j])){
			processedText[j++] = tolower(text[i]);
			if(j>1 && processedText[j-1] == processedText[j-2]){
				processedText[j-1] = 'x';
				processedText[j++] = tolower(text[j]);
			}
		}
	}
	if(j%2!=0) processedText[j++]='x';
	processedText[j]='\0';
}

void encryptedPlayfair(char text[], char encryptedText[]){
	int i, row1, col1, row2, col2;
	for(i=0;text[i]!='\0';i+=2){
		findPosition(text[i],&row1, &col1);
		findPosition(text[i+1],&row2, &col2);
		
		if(row1==row2){
			encryptedText[i]=keyMatrix[row1][(col1+1)%SIZE];
			encryptedText[i+1]=keyMatrix[row2][(col2+1)%SIZE];
		} else if(col1==col2){
			encryptedText[i]=keyMatrix[(row1+1)%SIZE][col1];
			encryptedText[i+1]=keyMatrix[(row2+1)%SIZE][col2];
		} else{
			encryptedText[i]=keyMatrix[row1][col2];
			encryptedText[i+1]=keyMatrix[row2][col1];
		}
	}
	encryptedText[i]='\0';	
}

void decryptPlayfair(char text[], char decryptedText[]){
	int i, row1, col1, row2, col2;
	for(i=0;text[i]!='\0';i+=2){
		findPosition(text[i],&row1, &col1);
		findPosition(text[i+1],&row2, &col2);
		
		if(row1==row2){
			decryptedText[i] = keyMatrix[row1][(col1-1+SIZE)%SIZE];
			decryptedText[i+1] = keyMatrix[row2][(col2-1+SIZE)%SIZE];
		} else if(col1==col2){
			decryptedText[i]=keyMatrix[(row1-1+SIZE)%SIZE][col1];
			decryptedText[i+1]=keyMatrix[(row2-1+SIZE)%SIZE][col2];
		} else{
			decryptedText[i]=keyMatrix[row1][col2];
			decryptedText[i+1]=keyMatrix[row2][col1];
		}
	}
	decryptedText[i]='\0';
}


int main() {
    char key[26], text[100], processedText[100], encryptedText[100], decryptedText[100];

    printf("Enter the key: ");
    scanf("%s", key);

    prepareKeyMatrix(key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    prepareText(text, processedText);

    encryptedPlayfair(processedText, encryptedText);
    printf("Encrypted Text: %s\n", encryptedText);

    decryptPlayfair(encryptedText, decryptedText);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}