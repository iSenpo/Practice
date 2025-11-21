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
int n;
string s[2];
bool ans = false;

bool dp(int i , int j, int t){
    if(i < 0 || j < 0 || i >= 2 || j > n){
        return false;
    }
    if(i == 1 && j == n - 1){
        if(s[i][j] == '1'){
            if(t == 1){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(t == 2){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    //t == 1 -> left to right
    if(t == 1){
        if(s[i][j] == '1'){
            return dp(i , j + 1 , 1);
        }
        else{
            return dp(i + 1 , j , 3) || dp(i - 1 , j , 2);
        }
    }
    //t == 2 bot to top
    if(t == 2){
        if(s[i][j] == '1'){
            return false;
        }
        else{
            return dp(i , j + 1 , 1);
        }
    }
    //t == 3 top to bot
    if(t == 3){
        if(s[i][j] == '1'){
            return false;
        }
        else{
            dp(i , j + 1 , 1);
        }
    }
}
void solve()
{
    cin >> n;
    cin >> s[0] >> s[1];
    fo(i , 2){
        fo(j , n){
            if(s[i][j] == '2'){
                s[i][j] == '1';
            }
        }
    }
    s[0] = s[0] + "0";
    s[1] = s[1] + "0";
    ans = dp(0 , 0 , 1);
    if(ans ) cout << "YES\n";
    else cout << "NO\n";
    ans = false;
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