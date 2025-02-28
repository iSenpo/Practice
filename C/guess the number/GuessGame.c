#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    const int Max = 100;
    const int Min = 1;
    int answer,guess,counter;
    

    srand(time(0));
    answer = (rand() % Max) + Min;

    do{
        
        printf("Guess a number between 1 - 100 :");
        scanf("%d",&guess);
        if(guess > answer){
            printf("Too High !");
            puts("~~~~~~~~~~~~~~~\n");
        }
        else if(guess < answer){
            printf("Too Low !");
            puts("~~~~~~~~~~~~~~~\n");
        }
        else{
            printf("CORRECT !");
        }
        counter++;
    }while(guess != answer);
    
    printf("\nAnswer : %d",answer);
    printf("\nGuesses : %d",counter);
    
    
    return 0;

}