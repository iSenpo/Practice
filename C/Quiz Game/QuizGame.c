#include <stdio.h>
#include <ctype.h>
int main (){
    
    char Questions[][100] = { 
        "1. What's The Ln(1) ?"
        ,"2. What does Pi equal to?"
        ,"3. What's the value of (1 + 1/n)^n ?"
    };
    char options[][100] = {
        "A. 1.31","B. -1.31","C. 1","D. 0",
        "A. P/r", "B. P*r", "C. Pr^2", "D. 2Pr",
        "A. PI", "B. Golden Raitio", "C. e","D. 1.999-"
    };
    
    char answer[3] = {'D','A','C'};
    char guess;

    int size = sizeof(Questions)/sizeof(Questions[0]);
    int counter;
    for(int i = 0; i <size ; i++){

        printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("%s\n",Questions[i]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
        
        for(int j = i*4 ; j < i*4+4  ; j++){
            printf("%s\n",options[j]);
            
        }
         printf("guess ?");
         scanf("%c",&guess);
         scanf("%c");
        guess=toupper(guess);

        if(guess == answer[i]){
            printf("Correct !\n");
            counter++;
        }
        else{
            printf("Wrong !\n");
        }
    }
    printf("\nYou'r Score is : %d/%d",counter,size);
    return 0;

}