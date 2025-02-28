#include <iostream>
using namespace std;

int main(){
int counter = 0;
int array[10];

for(int i=0 ; i<=9 ; i++){

    cout<<"\nEnter "<<i+1<<"th Number:" ;
    cin>>array[i];
    if(array[i] > 0){
        counter++;
    }
}
for(int i=0 ; i<=9 ; i++){
    if(array[i] < 0){ cout<<array[i]<<"  " ;}
}
for(int i=0 ; i<=9 ; i++){
    if(array[i] > 0){ cout<<array[i]<<"  " ;}
}
cout<<"\nPositive Numbers:"<<counter<<"\nNegative Numbers:"<<10-counter;

return 0;}

//Shayan Erfanian - 40311126044