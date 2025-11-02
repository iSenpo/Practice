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

const int N  = 2e5 + 10;
//always check input!!!

int MOD = 998244353;
int n;
vector<int> a(101 , 0) , b(101 , 0);

ll dp(int i , bool swaped){
    if(i == n){
        if(!swaped){
            if(a[i] >= a[i - 1] && b[i] >= b[i - 1]){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
           if(a[i] >= b[i - 1] && b[i] >= a[i - 1]){
                return 1;
            }
            else{
                return 0;
            } 
        }
    }
    if(swaped){
        if(a[i] < b[i -1] || b[i] < a[i - 1]){
            return 0;
        }
    }
    else{
        if(a[i] < a[i - 1] || b[i] < b[i - 1]){
            return 0;
        }
    }
    return (dp(i + 1 , true) + dp(i + 1 , false)) % MOD;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> b[i];
    }
    cout << (dp(1 , true) + dp(1 , false)) % MOD << ln;
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