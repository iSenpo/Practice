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
    int n , k;
    cin >> n >> k;
    int a[n];
    fo(i , n) cin >> a[i];
    vector<int> t(a , a + n);
    sort(all(t));
    vector<int> v;
    ll sum = 0;
    for(int i = n - k; i < n ; i++){
        v.pb(t[i]);
        sum += t[i];
    }
    cout << sum << ln;
    int cnt = 0;
    int i = 0;
    int last = 0;
    int snt = 0;
    for(int j = 0 ; j < v.size() - 1 ; j++){
        cnt++;
        if(i >= n){
            break;
        }
        while(a[i] != v[j] && i < n){
            cnt++;
            i++;
        }
        cout << cnt << ' ';
        snt += cnt;
        cnt = 0;
        last = snt;
        i++;
    }
    cout << n - last << ' ';
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