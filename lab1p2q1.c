#include <stdio.h>
#include <stdlib.h>

void stringPercent();
void intDiff(int a, int b);
void floatDiv(float a, float b);

int main(void) {
    stringPercent();
    intDiff(10,3);
    floatDiv(1.000000f, 3.000000f);
    return 0;
}

void stringPercent(){
    printf("One half is 50%%\n");
}

void intDiff(int a, int b){
    int diff = a - b;
    printf("The difference between %d and %d is %d\n", a, b,diff);
}

void floatDiv(float a, float b){
    float div =  a / b;
    printf("%f / %f is %f\n", a, b, div);
}