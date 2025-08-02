#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*---------------------------------*/
    int n , k;
    cin >> n >> k;
    vector<ll> dp(n + 1 , 0);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    for(int i = 0; i < n ; i++)
        if(arr[i] > 0)
            dp[i] += arr[i];
        
    ll Max = 0;
    for(int i = 0; i <= n-k ; i++){
        ll left = i;
        ll right = i + k - 1;
        Max = max(Max , (dp[left] - dp[0])+(dp[right] - dp[left])+(dp[n-1] - dp[right]));
    }
    cout << Max ;
    return 0;
}