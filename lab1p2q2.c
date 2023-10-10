#include <stdio.h>
#include <stdlib.h>

void intSum();
void floatProd();
void doubledWord();

int main(void){
    intSum();
    floatProd();
    doubledWord();
    return 0;
}

void intSum(){
    int a, b, sum;
    printf("Give two integers: ");
    scanf("%d %d", &a, &b);

    sum = a+b;
    printf("You entered %d and %d, their sum is: %d\n", a, b, sum);
}

void floatProd(){
    float a, b, prod;
    printf("Give two floats: ");
    scanf("%f %f", &a, &b);

    prod = a * b;
    printf("You entered %f and %f, their product is: %f\n", a, b, prod);
}

void doubledWord(){
    char myWord[100];
    printf("Give a word: ");
    scanf("%s", myWord);

    printf("%s %s\n", myWord, myWord);
}
