#include <stdio.h>

int main(){

char unit;
float tempture;

printf("\nIs the tempture in (F) or (C)? ");
scanf("%c",&unit);

unit = toupper(unit); //to turn c into C 

if(unit == 'F'){
    printf("The tempture is in Fahrenheit! \n");
    printf("Enter your Tempture in Fahrenheit:");
    scanf("%f",&tempture);
    tempture=(tempture-32)*5/9;
    printf("The tempture in Celsius is: %.2f",tempture);
}
else if(unit == 'C'){
    printf("The tempture is in Celsius! \n");
    printf("Enter your Tempture in Celsius:");
    scanf("%f",&tempture);
    tempture=(tempture*9/5)+32;
    printf("The tempture in Fahrenheit is: %.2f",tempture);
}
else{
    printf("Not Valid !");
}
return 0;}