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
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> st , st2;
    int diff;
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    int Max = 0;
    fo( i , n - 1){
        st2.insert(a[i]);
        diff = a[i + 1] - a[i];
        st.insert(diff);
        if(diff != 0){
            Max = diff;
        }
    }
    st2.insert(a[n -1]);
    if(st2.size() <= 2){
        if(a[0]%2 == a[n - 1]%2){
            cout << (a[n - 1] - a[0])/2 << ln;
            return;
        }
    }
    if(st.size() > 2){
        cout << -1 << ln;
    }
    else{
        cout << Max << ln;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow