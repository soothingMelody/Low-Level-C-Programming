#include <stdio.h>

//function for exercise 1
void printInReverse(){
    char str = getchar();
    if (str != '\n'){
        printInReverse();
        if (str != ' '){
            putchar(str);
        }
    }
}
//function for exercise 2
int sumOfDigits(int n){
    if(n==0){
        return 0;
    }
    else {
        return (n % 10) + sumOfDigits(n/10);
    }
}

int isAutomorphic(int n){
    int square = n * n;
    if(n == 0){
        return 1;
    }
    else if (n % 10 != square % 10){
        return 0;
    }
    else{
        return isAutomorphic(n/10);
    }
    
}

void findAutomorphicNumbers(int a, int b){
    if(a > b){
        return;
    }
    if(isAutomorphic(a)){
        printf("%d", a);
    }
    findAutomorphicNumbers(a+1,b);
}

int main(){
    //Exercise 1
    printf("Exercise 1.\nThis program will reverse a given string.\n");
    printf("Type anything and press the enter key: ");
    printInReverse();

    //Exercise 2
    int userNumber;
    printf("\n\nExercise 2.\nThis program will sum up the digits of your number.\n");
    printf("Type in your number ");
    scanf("%d", &userNumber);
    int sum= sumOfDigits(userNumber);
    printf("Sum of the digits: %d\n", sum);

    //Exercise 3
    int a;
    int b;
    printf("\n\nExercise 3.\nEnter the closed interval [a, b]: \n");
    scanf("%d %d", &a, &b);
    printf("Automorphic numbers in the interval [%d, %d]: ", a, b);
    findAutomorphicNumbers(a, b);
    printf("\n");

    return 0;
}