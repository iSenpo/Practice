#include <stdio.h>
int main(){

const double Pi=3.14159;
float radius;
float A;
float P;
 
 printf("\nEnter the radius of the Circle:");
 scanf("%f",&radius);
 A = Pi * radius * radius;
 P = 2 * Pi * radius;
 printf("The Area is : %.2f \t the Circumference is : %.2f ",A,P);



return 0;}