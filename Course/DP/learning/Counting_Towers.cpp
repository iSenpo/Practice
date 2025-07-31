#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        vector<vector<ll>> dp(n , vector<ll>(8 , 0));
        //base :
        fo(i , 8) {
            dp[0][i] = 1;
        }
        for(int i = 1 ; i < n ; i++)
        {
            fo(j , 8)
            {
                if(j == 1 || j == 6 || j == 7)
                {
                    dp[i][j] = (dp[i-1][2] + dp[i-1][6] + dp[i-1][7])%MOD;
                }
                else
                {
                    dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%MOD;
                }
            }
        }
        cout << (dp[n-1][2] + dp[n-1][7]) % MOD << ln;
    }
    return 0;
}