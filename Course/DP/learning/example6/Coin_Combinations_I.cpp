#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int n,x;
int a[N];
int dp[N];

int coin(int i){
    //base :
    if(i == 0){
        return 0;
    }
    if(i < 0 || n == 0){
        return 1;
    }
    //dp :
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 0;
    for(int j = 0; j<n ; j++){
        dp[i] += dp[i - a[j]];
    }
    return dp[i];
}
int main(){
    cin >> n >> x; 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    memset(dp , -1 , sizeof(dp));

    cout << coin(x);
    return 0;
}