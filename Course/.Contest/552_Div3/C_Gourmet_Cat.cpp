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
    int a , b , c;
    cin >> a >> b >> c;
    int per[3] = {2 , 3 , 4};
    ll ans = 0;
    int Min = min (a , min(b , c));
    ans += (Min*3);
    a -= Min;
    b -= Min;
    c -= Min;
    if(c == 0){
        int k = 4;
        while(k && b > 0 && a > 0){
            ans+=2;
            b--;
            a--;
            k--;
        }
        if(a){
            ans++;
            a--;
        }
        else if(b && k != 4){
            ans++;
            b--;
        }
    }
    else if(b == 0){
        int k = 3;
        while(k-- && a > 0 && c > 0){
            ans+=2;
            a--;
            c--;
        }
        if(a){
            ans++;
            a--;
        }
        else if(c){
            ans++;
            c--;
        }
    }
    else if(a == 0){
        int k = 2;
        while(k-- && b > 0 && c > 0){
            ans+=2;
            b--;
            c--;
        }
        if(c){
            ans++;
            c--;
        }
        else if(b){
            ans++;
            b--;
        }
    }
    cout << ans << ln;
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