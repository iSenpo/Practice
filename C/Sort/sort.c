#include <stdio.h>


void sort(int array[] , int size){

    for(int i=0 ; i < size-1 ; i++){

        for(int j=0 ;j < size -1 ;j++){

            if(array[j] > array[j+1]){

                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void PrintArray(int array[] , int size){
    for(int i=0; i < size; i++){
        printf("%d ",array[i]);
    }
}
int main(){

int array[]={8,3,6,1,9,2,7,4,5};
int size = sizeof(array)/sizeof(array[0]);

    sort(array,size);
    PrintArray(array,size);

   
return 0;}