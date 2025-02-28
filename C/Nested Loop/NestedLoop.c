#include <stdio.h>
#include <string.h>

int main(){

int rows;
int colums;
char symbol;

    printf("\nEnter Number Of Rows :");
    scanf("%d",&rows);

    printf("\nEnter Number Of Colums :");
    scanf("%d",&colums);

    scanf("%c");

    printf("\nEnter Symbol :");
    scanf("%c",&symbol);

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= colums; j++)
        {
        printf("%c  ",symbol);
        }

    printf("\n");
    
    }
return 0;}