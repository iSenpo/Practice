#include <stdio.h>
#include <stdlib.h>

int main(){

   unsigned int i;
   unsigned int seed;
    
    printf("Enter Seed :");
    scanf("%u",&seed);
    srand(seed);
    
       for(i= 1 ; i<=20 ; i++){

      printf("%d\t",rand()%6 + 1);
      
      if(i % 5 == 0){
         puts("");
      }
   }
}