#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    int k , n , a , b;
    cin >> k >> n >> a >> b;
    int ans = 0;
    if(n * b >= k){
        cout << -1 << ln;
        return;
    }
    while(k - a > b*(n - 1) && n > 0){
        k -= a;
        n--;
        ans++;
    }
    if(k <= b && k <= a){
        cout << -1 << ln;
        return;
    }
    if(n > 0){
        k -= b * n;
    }
    if(k <= 0){
        cout << -1 << ln;
        return;
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow