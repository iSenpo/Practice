#include <stdio.h>

void birthday(char name[],int age){
    printf("HBD dear %s\n",name);
    printf("you're now %d years old\n",age);
}
double square(double x){
    double result = x * x;
    return result;
    //or you can just say : return x * x;
}
int FindMax(x , y){
if (x > y)
{
   return x;
}
else {
    return y;
}

}
int main(){
    char name[] = "cAli";
    int age = 18;
    birthday(name,age);

    double x = square(3.14);
    printf("The Square of PI is : %.3lf\n",x);

    int Max = FindMax(8 , 4);
    printf("%d\n",Max);
    return 0;
}