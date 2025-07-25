//Dice Combinations 1634
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;
const int MOD = 1e9 + 7;

ll dp[N];
int Dice(int i){
    //base : 
    if(i < 0){
        return 0;
    }
    if(i == 0){
        return 1;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 0;
    for(int k = 1; k <= 6 ; k++){
        dp[i] += Dice(i - k)%MOD;
        dp[i] %= MOD;
    }
    return dp[i];
}
int main(){
    int n;
    cin >> n;
    memset(dp , -1 , N);
    cout << Dice(n); 
    return 0;
}