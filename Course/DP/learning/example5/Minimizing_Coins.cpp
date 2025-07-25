//https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;
int Maxx = 2e9;
int n;
vector<int> dp(N,-1);
int a[N];

int Coin(int i){
    //base :
    if(i == 0){
        return 0;
    }
    if(i < 0){
        return Maxx;
    }
    //dp:
    if(dp[i] != -1){
        return dp[i];
    }
    int res = Maxx;
    for(int j = 0; j < n ; j++){
        res = min( res , Coin(i - a[j]) + 1 );
    }
    return dp[i] = res;
} 
int main(){
    int x;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int ans = Coin(x);
    if(ans == Maxx){
        cout << -1 ;
    }
    else{
        cout << ans;
    }
    return 0;
}