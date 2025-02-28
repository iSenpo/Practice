#include <stdio.h>
int main(){
   
   int numbers[3][3] = {{3 , -1 , 5} , {4 , 6 , -7} , {-9 , -8 , 7}};
   
   int rows = sizeof(numbers)/sizeof(numbers[0]);
   int colums = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("Number Of rows: %d\n",rows);
    printf("Number Of colums: %d\n",colums);

    for(int i = 0 ; i < rows ; i++){  //i<=2
    for(int j= 0; j < colums; j++){   //j<=2
        printf("%3d ",numbers[i][j]);
    }
    printf("\n");
   }
   return 0;

}