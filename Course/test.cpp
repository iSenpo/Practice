#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n ; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 0; i < n ; i){
        if(i+1 == n-1){
            sum+=a[++i];
        }
        if(a[i+1] > 0){
            sum+=a[++i];
        }
        else{
            i+=2;
            sum+=a[i];
        }
    }
    cout << sum ;

    return 0;
}