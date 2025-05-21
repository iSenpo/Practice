#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* ptr = new int[n];
    for(int i =0 ; i<n ; i++){
        cin>>ptr[i];
    }

    int max = ptr[0],min = ptr[0];
    int sum = 0, avg = 0;

    for(int i =0 ; i<n ; i++){
        if(ptr[i] > max){
            max = ptr[i];
        }
        if(ptr[i] < min){
            min = ptr[i]; 
        }
        sum += ptr[i];
    }
    avg = sum/n ;

    int *left = ptr;
    int *right = ptr + n - 1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    cout<<"Max : "<<max<<"\nMin : "<<min<<"\nSum : "
    <<sum<<"\nAvg : "<<avg;

    for(int i =0 ; i<n ; i++){
        cout<<"\n"<<ptr[i];
    }
    return 0;
}