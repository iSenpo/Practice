//https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;

const int N  = 1e6 + 500;
const int MOD = 1e9 + 7;

vector<unsigned long long> dp(N , -1);
unsigned long long Dice(long long i){
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
        dp[i] = (dp[i] + Dice(i - k)) % MOD ;
    }
    return dp[i];
}
int main(){
    long long n;
    cin >> n;
    cout << Dice(n);
    return 0;
}