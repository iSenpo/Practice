#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<ll> odd;
    vector<ll> even;
    ll x;
    fo(i , n){
        cin >> x;
        if(x%2){
            odd.pb(x);
        }
        else{
            even.pb(x);
        }
    }
    sort(all(odd));
    sort(all(even));
    bool one = false;
    bool two = false;
    bool three = false;
    int ptr = 0;
    vector<int> ans;
    for(int i = 0 ; i < odd.size() - 2 ; ++i){
        if((odd[i] + odd[i + 1] + odd[i + 2]) / 3 == odd[i + 1]){
            three = true;
            ans.pb(odd[i]);
            ans.pb(odd[i + 1]);
            ans.pb(odd[i + 2]);
            break;
        }
    }
    if(three){
        cout << 3 << ln;
        for(int i : ans)
            cout << i << ' ';
        return;
    }
    for(int i = 0 ; i < odd.size() - 1 ; ++i){
        if((odd[i] + odd[i + 1] + odd[i + 2]) / 3 == odd[i + 1]){
            three = true;
            ans.pb(odd[i]);
            ans.pb(odd[i + 1]);
            ans.pb(odd[i + 2]);
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}