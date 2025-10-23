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
    int n;
    cin >> n;
    int m = n/6;
    int a[n];
    vector<vector<int>> need(m ,vector<int>({4, 8, 15, 16, 23, 42 , 0}));
    vector<int> k(m , 0);
    fo(i , n){
        cin >> a[i];
        fo(j , m){
            if(a[i] == need[j][k[j]]){
                k[j]++;
                break;
            }
        }
    }
    ll ans = 0;
    fo(i , m){
        if(k[i] == 0){
            ans += 6;
            n -= 6;
        }
        else{
            ans += k[i]%6;
            n -= k[i]%6;
        }
    }

    cout << ans + n%6 << ln;
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