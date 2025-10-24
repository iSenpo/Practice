#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define F first
#define S second
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
    vector<pair<int , vector<int>>> x(n , {0 , vector<int>(4)}) , y(n , {0 , vector<int>(4)});
    fo(i , n){
        int X , Y , f1 , f2 , f3 , f4;
        cin >> X >> Y >> f1 >> f2 >> f3 >> f4;
        x[i] = {X , {f1 , f2 , f3 , f4}};
        y[i] = {Y , {f1 , f2 , f3 , f4}};
    }
    sort(all(x));
    sort(all(y));
    vector<int> cantmove;
    fo(i , n){
        if(!x[i].S[0] && !x[i].S[3]){
            cantmove.pb(i);
        }
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