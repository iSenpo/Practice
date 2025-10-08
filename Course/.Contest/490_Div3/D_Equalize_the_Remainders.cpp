#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(ll i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const ll dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
ll MOD = 1e9 + 7;

const ll N  = 2e5 + 10;
//always check input!!!

void solve()
{
    ll n , k;
    cin >> n >> k;
    ll a[n];
    ll m = n / k;
    vector<ll> inp(k , 0);
    vector<ll> fre;
    fo(i , n){
        cin >> a[i];
        ll j = a[i] % k;
        if(inp[j] >= m){
            fre.pb(i);
        }
        else{
            inp[j]++;
        }
    }
    ll ans = 0;
    for(ll i = 0 ; i < k ; i++){
        while(inp[i] < m){
            ll index = fre.back();
            fre.pop_back();
            ll r = a[index] % k;
            ll inc = (i - r + k) % k;
            a[index] += inc;
            ans += inc;
            inp[i]++;
        }
    }
    cout << ans << ln;
    for(ll i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check ll overflow