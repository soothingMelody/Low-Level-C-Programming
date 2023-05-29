#include <stdio.h>
#include <math.h>

//Repeat character function
void repeat (char c, int count){
    for (int i = 0; i<count; i++){
        printf("%c",c);
    }
}
//Printing the triangle for Exercise 2
void printTriangle(int height){
    int i, j;
    for (i = 0; i <= height; i++){
        for(j = 0; j < height - i; j++){
            printf(" ");
        }
        for(j = 0; j<(2*i)-1;j++){
            printf("X");
        }
        printf("\n");
    }
}
//Returns S of the formula from the third task
double formula3(int n, int a){
    double S;
    for (int i = 1; i<=n; i++){
        S+= (a*(pow(i, 3)) - 7) / (pow(i, 2) + 1);
    }
    return S;
}
//Returns R of the formula from the fourth task
double formula4(int n, int m){
    double R;
    for(int i = 1; i <=n; i++){
        double temp = 1;
        for (int j = 1; j<=n; j++){
            temp*= (pow(i,2)+pow(j,2)-1) / (2*i+3*j+4);
        }
        R+= temp;
    }
    return R;
}
//Checking if a number is perfect
int isPerfectNumber(int number){
    int sum = 0;
    for (int i = 1; i <= number / 2; i++){
        if(number % i == 0){
            sum += i; //summing up the dividers
        }
    }
    if(sum == number){ //Checking it it fulfills the conditions
        return 1; //Yes it is
    }
    else{
        return 0; //No it isn't
    }
    
}
//Counting the perfect numbers
void perfectNumberFinder(int a){
    printf("\nThe perfect numbers in the range %d are: ", a);
    for (int number = 1; number <=a; number++){
        if(isPerfectNumber(number)){
            printf("%d ", number);
        }
    }
    printf("\n");
}

int sumOfDivisors(int num){
    int sum = 1;
    for (int i = 2; i*i < num; i++){
        if(num % i == 0){
            sum +=i;
            if (i*i != num)
                sum += num / i;
        }
    }
    return sum;
}

int main(){
    //Exercise 1
    printf("Exercise 1.\nAutomatically prints a tower.\n");
    for(int i = 0; i < 5; i++){
        repeat('O', (i+1));
        printf("\n");
    }

    //Exercise 2
    int h;
    printf("\nExercise 2.\nPrints a triangle.\nProvide the height of the triangle: ");
    scanf("%d", &h);
    printTriangle(h);

    //Exercise 3
    printf("\nExercise 3.\nCalculates the value of the formula.\n");
    int n, a;
    printf("Input the values of n and a(Space between each): ");
    scanf("%d %d", &n, &a);
    printf("\nThe value of S is %lf.\n", formula3(n, a));

    //Exercise 4
    printf("\nExercise 4.\nCalculates the value of the formula.\n");
    int n1, m1;
    printf("Input the values of n and m(Space between each: ");
    scanf ("%d %d", &n1, &m1);
    printf("\nThe value of R is %lf.\n", formula4(n1, m1));

    //Exercise 5
    int g;
    printf("\n\nExercise 5.\nThis program will return all the perfect numbers in a certain range\nPlease, specify the range: ");
    scanf("%d", g);
    perfectNumberFinder(g);
    
    //Exercise 6
    int h;
    printf("\n\nExercise 6.\nLists pairs of amicable numbers in a range.\n");
    printf("Enter the range: 1 to: ");
    scanf("%d", &h);
    printf("\nList:\n");
    for(int i = 1; i <= h; i++){
        int sum1 = sumOfDivisors(i);
        int sum2 = sumofDivisors(sum1);
    
        if(i != sum1 && i == sum2 && i < sum1){
            printf("(%d, %d)\n", i, sum1);
        }
    }
    return 0;
}