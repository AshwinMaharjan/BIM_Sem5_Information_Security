#include<stdio.h>
int gcdIterative(int a,int b){
while (b!=0){
int temp = b;
b= a % b;
a= temp;
}
return a;
}
 

int main(){
int num1,num2;
printf("\n\nEnter two numbers: ");
scanf("%d %d", &num1, &num2);
printf("GCD (Iterative of %d and %d is: %d\n", num1, num2, gcdIterative(num1,num2));
 

}