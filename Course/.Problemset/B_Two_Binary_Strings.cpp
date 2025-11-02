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
    string s , t;
    cin >> s >> t;
    int cnt1s = 0;
    int cnt1t = 0;
    int cnt0s = 0;
    int cnt0t = 0;
    int n = sz(s);
    for(int i = 0; i < n ; i++){
        if(s[i] == '0'){
            cnt0s++;
        }
        if(t[i] == '0'){
            cnt0t++;
        }
        if(cnt0s != cnt0t){
            if(s[i - 1] == '1'){
                break;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(s[i] == '1'){
            cnt1s++;
        }
        if(t[i] == '1'){
            cnt1t++;
        }
        if(cnt1s != cnt1t){
            if(t[i + 1] == '0'){
                break;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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