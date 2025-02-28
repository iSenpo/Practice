#include <stdio.h> 
#include <string.h>
       
int main(){
    double n;       
    double S;

    while(n != 0){

        printf("\nEnter Numbers To Sum (Enter 0 to calculate) :");
        scanf("%lf",&n);
        S += n ; 
    }
    printf("\nThe Sum Of All Numbers Above Is : %.2lf",S);
return 0;}
