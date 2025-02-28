#include <stdio.h>

int FindMax(int x , int y , int z);

int FindMax(int x,int y, int z){

    int max = x;

    if(y>max){  max = y; }

    if(z>max){  max = z; }

return max;}

int main(){
    int n1,n2,n3;

    printf("Enter 3 Numbers to Get Max :");
    scanf("%d%d%d",&n1,&n2,&n3);

    int result = FindMax(n1,n2,n3);
    printf("The Maximum is : %d",result);

return 0;    
}
