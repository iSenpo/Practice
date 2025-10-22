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
    int a[n];
    fo(i , n) cin >> a[i];
    vector<int> l , r;
    fo(i , n - 1){
        if(a[i] < a[i + 1]){
            l.pb(a[i]);
        }
        else{
            l.pb(a[i]);
            break;
        }
    }
    for(int i = n - 1 ; i >= 0 ; --i){
        if(a[i] < a[i - 1]){
            r.pb(a[i]);
        }
        else{
            r.pb(a[i]);
            break;
        }
    }
    if(l.empty() && r.empty()){
        cout << 1 << ln << 'R' << ln;
        return;
    }
    int ptl = 0;
    int ptr = 0;
    int last;
    string ans ;
    while(ptl < sz(l) && ptr < sz(r)){
        if(l[ptl] < r[ptr]){
            ans += 'L';
            last = l[ptl];
            ptl++;
        }
        else if(r[ptr] < l[ptl]){
            ans += 'R';
            last = r[ptr];
            ptr++;
        }
        else if(l[ptl] == r[ptr]){
            if(sz(l) - ptl > sz(r) - ptr){
                while(ptl <= sz(l)){
                    ans += 'L';
                    ptl++;
                }
            }
            else{
                while(ptr <= sz(r)){
                    ans += 'R';
                    ptr++;
                }
            }
            break;
        }
    }
    while(ptr < sz(r)){
        if(r[ptr] < last){
            ans += 'R';
            last = r[ptr];
            ptr++;
        }
        else{
            break;
        }
    }
    while(ptl < sz(l)){
        if(l[ptl] < last){
            ans += 'L';
            last = l[ptl];
            ptl++;
        }
        else{
            break;
        }
    }
    cout << sz(ans) << ln << ans << ln;

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