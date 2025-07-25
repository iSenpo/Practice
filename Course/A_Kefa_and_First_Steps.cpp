#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int n;
    cin >> n;
    int a[n];
    int Max = 1;
    int counter = 1;
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] < a[i-1]){
            counter = 1;
        }
        else{
            counter++;
        }
        Max = max(Max , counter);
    }
    cout << Max ;
    return 0;
}