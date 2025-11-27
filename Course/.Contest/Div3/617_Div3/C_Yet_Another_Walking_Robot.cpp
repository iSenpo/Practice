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

const int N  = 1e9;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    int Min = N;
    pii base = {0 , 0};
    pii ans;
    int dx = 0 , dy = 0;
    map<pii , int> ind;
    map<char , int> cnt;
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == 'D'){
            dy--;
        }
        if(s[i] == 'U')
            dy++;
        if(s[i] == 'R')
            dx++;
        if(s[i] == 'L')
            dx--;
            
        base.first += dx;
        base.second += dy;
        if(ind[base] != 0){
            if(i - ind[base] < Min){
                Min = i - ind[base];
                ans = {i + 1 , ind[base] + 1};
                ind[base] = i;
            }
        }
        else{
            ind[base] = i;
        }
    }
    if(Min == N){
        cout << -1 << ln;
    }
    else{
        cout << ans.first << ' ' << ans.second << ln;
    }
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