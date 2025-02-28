#include <stdio.h>
int main(){

char grade;

printf("Enter your grade :");
scanf("%c",&grade);

grade = toupper(grade); // a ===> A , b ===>B , ...

switch (grade)
{
case 'A' :
    printf("Greate!");
    break;

case 'B' :
    printf("Good!");
    break;

case 'C' :
    printf("Not Bad At all");
    break;

case 'D' :
    printf("Hmmm");
    break;

case 'F' :
    printf("Failed!");
    break;

default: printf("Enter valid grades !");
    break;
}

return 0;}