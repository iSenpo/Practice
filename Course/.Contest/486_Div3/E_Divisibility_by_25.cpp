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
    string s;
    cin >> s;
    vector<int> ind0;
    vector<int> ind5;
    vector<int> ind2;
    fo(i , sz(s)){
        if(s[i] == '0'){
            ind0.pb(i);
        }
        if(s[i] == '5'){
            ind5.pb(i);
        }
        if(s[i] == '2' || s[i] == '7'){
            ind2.pb(i);
        }
    }
    sort(all(ind0));
    sort(all(ind5));
    sort(all(ind2));
    if(ind5.empty() && sz(ind0) < 2){
        cout << -1;
        return;
    }
    if(ind0.empty() && ind2.empty()){
        cout << -1;
        return;
    }
    if(ind2.empty() && ((ind0.size() < 2) || (ind5.empty()))){
        cout << -1;
        return;
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