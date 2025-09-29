#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
typedef long long ll;

const int N  = 1e17;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = N;
    //calculate for 'a'
    vector<ll> pref_a(n , 0);
    int cnt = (s[0] == 'a');
    for(int i = 1 ; i < n ; ++i){
        if(s[i] == 'a'){
            cnt++;
            pref_a[i] = pref_a[i - 1];
        }
        else{
            pref_a[i] = pref_a[i - 1] + cnt;
        }
    }
    vector<ll> suff_a(n , 0);
    cnt = (s[n-1] == 'a');
    for(int i = n-2 ; i >= 0 ; --i){
        if(s[i] == 'a'){
            cnt++;
            suff_a[i] = suff_a[i + 1];
        }
        else{
            suff_a[i] = suff_a[i + 1] + cnt;
        }
    }
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'a'){
            ans = min(ans , pref_a[i] + suff_a[i]);
        }
    }
    vector<ll> pref_b(n , 0);
    cnt = (s[0] == 'b');
    for(int i = 1 ; i < n ; ++i){
        if(s[i] == 'b'){
            cnt++;
            pref_b[i] = pref_b[i - 1];
        }
        else{
            pref_b[i] = pref_b[i - 1] + cnt;
        }
    }
    vector<ll> suff_b(n , 0);
    cnt = (s[n-1] == 'b');
    for(int i = n-2 ; i >= 0 ; --i){
        if(s[i] == 'b'){
            cnt++;
            suff_b[i] = suff_b[i + 1];
        }
        else{
            suff_b[i] = suff_b[i + 1] + cnt;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'b'){
            ans = min(ans , pref_b[i] + suff_b[i]);
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}