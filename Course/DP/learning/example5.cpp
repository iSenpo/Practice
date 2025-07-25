#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int n;
int dp[N];
int a[N];

int Coin(int i){
    //base :
    if(i < 0){
        return 0;
    }
    //dp:
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 0;
    for(int j = 0; j < n ; j++){
        dp[i] = min(dp[i] , dp[i - a[j]]);
    }
} 
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    
    return 0;
}