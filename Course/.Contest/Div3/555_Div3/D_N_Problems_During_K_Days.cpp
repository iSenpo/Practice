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
    ll n , k;
    cin >> n >> k;
    ll sum = 0;
    ll a[k];
    fo(i , k){
        a[i] = i + 1;
        sum += i + 1;
    }
    if(n < sum){
        cout << "NO\n";
        return;
    }
    ll d = n / sum;
    sum = 0;
    fo(i , k){
        a[i] = d + i;
        sum += d + i;
    }
    int cnt = 0;
    while(sum + k < n){
        cnt++;
        n -= (k * cnt);
    }
    n -= sum;
    fo(i , k){
        a[i] += cnt;
        sum += cnt;
    }
    fo(j , 1000){
        for(int i = k - 1 ; i >= 1 ; i--){
            ll Max = (a[i - 1] * 2) - a[i];
            ll v = min(n , Max);
            n -= v;
            a[i] += v;
        }
        if(n > 0){
            ll Max = (a[1] - 1) - a[0];
            ll v = min(n , Max);
            n -= v;
            a[0] += v;
        }
    }
    if(n > 0){
        cout << "NO\n";
        return;
    }
    fo(i , k - 1){
        if(a[i] >= a[i + 1]){
            cout << "NO\n";
            return;
        }
        if(a[i + 1] > a[i]*2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    fo(i , k){
        cout << a[i] << ' ';
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow