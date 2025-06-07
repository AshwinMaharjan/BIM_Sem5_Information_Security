#include<stdio.h>
#include<string.h>

void encryptRailFence(char *text,int key){
    int len = strlen(text);
    char rail[key][len];
    int i,j,dir_down=0,row=0,col=0;
    
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';
    
    for(i=0;i<len;i++){
        if(row == 0 || row == key-1)
            dir_down=!dir_down;
        
        rail[row][col++]=text[i];
        
        row += dir_down ? 1 : -1;
    }
    
    printf("Encrypted text: ");
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]!='\n')
                printf("%c",rail[i][j]);
    printf("\n");
}

void decryptRailFence(char *cipher,int key){
    int len=strlen(cipher);
    char rail[key][len];
    int i,j,dir_down=0,row=0,col=0;
    
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
            rail[key][len]='\n';
    
     for(i=0;i<len;i++){
        if(row == 0 || row == key-1)
            dir_down=!dir_down;
        
        rail[row][col++]='*';
        
        row += dir_down ? 1 : -1;
    }
    
    int index = 0;
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]=='*' && index < len)
                rail[i][j] = cipher[index++];
        
    row=0,col=0;
    dir_down=0;
    printf("Decrypted Text: ");
    for(i=0;i<len;i++){
        if(row == 0 || row == key -1 )
            dir_down = !dir_down;
            
        printf("%c",rail[row][col++]);
        
        row +=dir_down?1:-1;
    }
    printf("\n");
}

int main(){
    char text[100],cipher[100];
    int key;
    
    printf("Enter text to encrypt: ");
    scanf("%s",text);
    printf("Enter a key: ");
    scanf("%d",&key);
    
    encryptRailFence(text,key);
    
    printf("\nEnter text to decrypt: ");
    scanf("%s",cipher);
    printf("Enter key: ");
    scanf("%d",&key);
    decryptRailFence(cipher,key);
}