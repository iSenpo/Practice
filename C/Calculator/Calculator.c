#include <stdio.h>
int main(){

char Operation;      
float n1;
float n2;
double result;

while (1)
{printf("\nEnter your Operation like (3+4) use:(+ - * /) : ");
scanf("%f %c %f",&n1,&Operation,&n2);
switch (Operation)
{
case '+' :
    result = n1 + n2;
    printf("The Sum is : %.2lf",result);
    break;

case '-' :
    result = n1 - n2;
    printf("The Substraction is : %.2lf",result);
    break;

case '*' :
    result = n1 * n2;
    printf("The Multiplication is : %.2lf",result);
    break;

case '/' :
if(n2 == 0){
    printf("Error!(Division by zero)");
    break;;
}
    result = n1 / n2;
    printf("The Division is : %.2lf",result);
    break;

default: printf("%c is Not a valid Operation",Operation);
    break;
}
}
    
    
    
return 0;}