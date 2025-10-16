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
ll cost(string s ,char ch){
    int n = sz(s);
    if(n == 1){
        if(s[0] == ch){
            return 0;
        }
        else{
            return 1;
        }
    }
    string p1 = s.substr(0 , n/2);
    string p2 = s.substr(n/2 , n/2);
    int cnt1 = 0;
    int cnt2 = 0;
    fo(i , n/2){
        if(p1[i] != ch){
            cnt1++;
        }
        if(p2[i] != ch){
            cnt2++;
        }
    }
    return min(cnt1 + cost(p2 , ch + 1) , cnt2 + cost(p1 , ch + 1));
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << cost(s , 'a') << ln;
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