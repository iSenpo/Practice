#include <stdio.h>
#include <math.h>

int main(){

float A;
float B;
float C;

printf("Enter Side A:");
scanf("%f",&A);

printf("Enter Side B:");
scanf("%f",&B);

C = sqrt(A*A + B*B);

printf("Side C is: %.2f",C);



return 0;}