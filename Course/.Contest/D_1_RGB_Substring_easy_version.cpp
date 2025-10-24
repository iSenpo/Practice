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
const char r[3] = {'R' , 'G' , 'B'};
const char g[3] = {'B' , 'R' , 'G'};
const char b[3] = {'G' , 'B' , 'R'};
int cost(string s){
    int n = sz(s);
    int ptr = 0;
    int ans1 = 0 , ans2 = 0 , ans3 = 0;
    fo(i , n){
        if(s[i] != r[ptr]){
            ans1++;
        }
        ptr++;
        if(ptr == 3){
            ptr = 0;
        }
    }
    ptr = 0;
    fo(i , n){
        if(s[i] != g[ptr]){
            ans2++;
        }
        ptr++;
        if(ptr == 3){
            ptr = 0;
        }
    }
    ptr = 0;
    fo(i , n){
        if(s[i] != b[ptr]){
            ans3++;
        }
        ptr++;
        if(ptr == 3){
            ptr = 0;
        }
    }
    int ans = min(ans1 , min(ans2 , ans3));
    return ans;
}
void solve()
{
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    int Min = N;
    for(int i = 0 ; i <= n - k ; i++){
        Min = min(Min , cost(s.substr(i , k)));
    }   
    cout << Min << ln;
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