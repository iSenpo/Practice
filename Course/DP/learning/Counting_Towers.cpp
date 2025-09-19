#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
ll MOD = 1e9 + 7;
const int N = 1e6;
vector<vector<ll>> dp;
inline int in(){
    int x;
    cin >> x;
    return x;
}
ll solve(int n , int i)
{
    //base :
    if(n == 1){
        return 1;
    }
    //transition :
    if(dp[n][i] != -1){
        return dp[n][i];
    }
    ll ans = 0;
    if(i == 0){
        ans += solve(n-1 , 0)%MOD;
        ans += solve(n-1 , 2)%MOD;
        ans += solve(n-1 , 1)%MOD;   
    }
    if(i == 1){
        ans += solve(n-1 , 1)%MOD;   
        ans += solve(n-1 , 2)%MOD;   
        ans += solve(n-1 , 3)%MOD;   
        ans += solve(n-1 , 4)%MOD;   
        ans += solve(n-1 , 5)%MOD;   
    }
    if(i == 2){
        ans += solve(n-1 , 0)%MOD;   
        ans += solve(n-1 , 1)%MOD;   
        ans += solve(n-1 , 2)%MOD;      
    }
    if(i == 3 || i == 4 || i == 5){
        ans += solve(n-1 , 1)%MOD;
        ans += solve(n-1 , 2)%MOD;
        ans += solve(n-1 , 3)%MOD;
        ans += solve(n-1 , 4)%MOD;
        ans += solve(n-1 , 5)%MOD;   
    }
    return dp[n][i] = ans%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        int n = in();
        dp.resize(n + 5 , vector<ll>(10 , -1));
        ll ans = (solve(n , 2)%MOD + solve(n , 1)%MOD)%MOD;
        cout << ans << ln;
    }
    return 0;
}