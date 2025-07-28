#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , x;
    cin >> n >> x;
    int h[n + 1] , s[n + 1];
    
    for(int i = 1; i <= n ; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> s[i];
    }
    vector<int> dp(x+1, 0);
    for (int j = 1; j <= n; j++) {
        for (int i = x; i >= h[j]; i--) {
            dp[i] = max(dp[i], dp[i - h[j]] + s[j]);
        }
    }
    cout << dp[x];
    return 0;
}