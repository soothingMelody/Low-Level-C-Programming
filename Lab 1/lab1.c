#include <stdio.h>
#include <math.h>

int main(){
    //Exercise 1
    double fir,sec,thir;
    printf("Exercise 1\nThis program will output the largest number\nEnter three numbers:\n");
    scanf("%lf %lf %lf",&fir, &sec, &thir);
    double list[] = {fir, sec, thir};
    double biggest = 0;

    for(int i = 0; i < 2; i++){
        if(list[i] > list[i+1]){
            if (list[i] > biggest){
                biggest = list[i];
            }
            else{
                continue;
            } 
        }
        else{
            if(list[i+1] > biggest){
                biggest = list[i+1];
            }
        }
    }
    printf("\nThe largest number out of these three is %lf\n", biggest);

    //Exercise 2
    float a;
    float b;
    printf("\n\nExercise 2\nThis program will calculate the value of a formula.\nEnter the value of a:\n");
    scanf("%f", &a);
    printf("\nEnter the value of b:\n");
    scanf("%f", &b);
    float result2 = (4.0*a)+2.0*((a-b-1.0)/((a*a)+(b*b)+1.0));
    printf("\nR = %f", result2);

    //Exercise 3
    int m,n;
    printf("\n\nExercise 3\nThis program will calculate the value of a formula.\nEnter the integer m:\n");
    scanf("%d", &m);
    printf("\nEnter the integer n:\n");
    scanf("%d", &n);
    float result3 = (5+(4+(3+2*(m-n-1))))/(((2*(m+n+1)-3)-4)-5);
    printf("T = %f", result3);

    //Exercise 4
    double x;
    printf("\n\nExercise 4\nThis program will calculate the value of a formula.\nEnter the value of x:\n");
    scanf("%lf", &x);
    double result4 = (sqrt(( (pow(sin(pow(x,3)), 2)) + 1.25)  /  ((pow((cos(pow(x,2))),3))+1.25))) / (log((pow((tan(x+2)),2)))+2.5);
    printf("N = %lf", result4);

    //Exercise 5
    int choice;
    printf("\n\nExercise 5\nMenu\nType in the necessary value:\n");
    printf("1 - If you want to convert from Celcius to Fahrenheit.\n");
    printf("2 - If you want to convert from Fahrenheit to Celcius.\n");
    printf("Any other value - Exit the program\n");
    scanf("%d", &choice);
    double fah,cel, result5;
    if(choice == 1){
        printf("\nYour choice has been made, C->F.\nPlease enter a value in Celcius that you want to convert:\n");
        scanf("%lf", &cel);
        result5 = (9/5)*cel + 32;
        printf("\n%lf degrees Celcius after conversion is %lf degrees Fahrenheit.\n", cel, result5);
    }
    else if(choice == 2){
        printf("\nYour choice has been made, F->C. \nPlease enter a value in Fahrenheit that you want to conver:\n");
        scanf("%lf",&fah);
        result5 = (5/9)*(fah - 32);
        printf("\n%lf degrees Fahrenheit after conversion is %lf degrees Celcius.\n", fah, result5);
    }
    else{
        printf("\nShutting down the program.\n");
    }

    //Exercise 6
    double a1, b1, a2, b2;
    printf("\n\nExercise 6\nThis program will calculate the point of intersection and distance of that point from the zero point of two straight lines.\nType in the values of a1 b1 a2 b2 (Space after each)\n");
    scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);
    double distance, clashx, clashy;
    clashx = (b2 - b1) / (a1 - a2);
    clashy = (a1*b2 - a2*b1) / (a1 - a2);
    distance = pow(pow(clashx, 2) + pow(clashy, 2), 0.5);
    printf("\nThe point of intersection of two lines is denoted by the coordinates (%lf, %lf).\nIt is also %lf units away from the zero point.\n", clashx, clashy, distance);
    
    //Exercise 7
    int aa, bb, cc;
    float x1, x2;
    printf("\n\nExercise 7\nThis program will find the roots of a quadratic equation\nType in the integer values of a, b and c for ax^2 + bx + c = 0\nSeparate each with a space\n");
    scanf("%d %d %d", &aa, &bb, &cc);
    if(aa == 0){
        printf("\nERROR Invalid Input\n");
    }
    float delta;
    delta = pow(bb, 2) - 4 * aa * cc;
    x1 = (-bb + delta) / (2*aa); 
    x2 = (-bb - delta) / (2*aa);
    printf("\nx1 = %f\nx2 = %f", x1, x2);
    return 0;
}