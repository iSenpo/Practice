#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;
const int MOD = 1e9 + 7;
ll n,x;
ll a[N];
vector<ll> dp(N , -1);

ll coin(int i){
    //base :
    if(i == 0){
        return 1;
    }
    if(i < 0 || n == 0){
        return 0;
    }
    //dp :
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 0;
    for(ll j = 0; j<n ; j++){
        dp[i] = (dp[i] + coin(i - a[j])) % MOD;
    }
    return dp[i];
}
int main(){
    cin >> n >> x; 
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << coin(x);
    return 0;
}