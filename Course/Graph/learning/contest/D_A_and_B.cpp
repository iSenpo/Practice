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
    int fb = 0;
    int lb = 0;
    bool ext = true;
    fo(i, n){
        if(s[i] == 'b'){
            lb = i;
            if(ext){
                fb = i;
                ext = false;
            }
        }
    }
    int p2 = fb + 1;
    int ans = 0;
    for(int p1 = fb ; p1 < lb ; p1++){
        if(s[p1] == 'a'){
            while(s[p2] == 'a'){
                p2++;
            }
            ans += p2 - p1;
            swap(s[p1] , s[p2]);
            p1 = p2;
        }
        p2++;
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