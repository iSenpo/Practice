#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    string s;
    cin >> s;
    int ctr1 = 0;
    int ctr0 = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            ctr1++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '0'){
            ctr0++;
        }
    }
    int ans = 0;
    for(int i = 0 ; i < ctr0 ; i++){
        if(s[i] == '1'){
            ans++;
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}