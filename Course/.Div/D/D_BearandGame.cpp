#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    if(a[0]>15){
        cout<<15;
        return 0;
    }
    for(int i = 1; i<n ;i++){
        if( (a[i]-a[i-1]) > 15){
            cout<<a[i-1]+15;
            return 0;
        }
    }
    if(90-a[n-1] > 15){
        cout<<a[n-1]+15;
        return 0;
    }
    cout<<90;
    return 0;
}
//9
//15 20 30 40 50 60 70 80 90
