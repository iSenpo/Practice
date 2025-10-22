#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()

void solve()
{
    int n , m;
    cin >> n >> m;
    vector<pair<int , int>> cnt(n);
    fo(i , n){
        cnt[i] = {0 , i + 1};
    }
    fo(i , m){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        cnt[v].first += 1;
        cnt[u].first += 1;
    }
    sort(all(cnt));
    cout << n/2 << ln ;
    for(int i = n - 1  ; i >= n/2 ; i--){
        cout << cnt[i].second <<' ';
    }
    cout << ln;
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