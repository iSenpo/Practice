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

bool pow2(int n){
    ll i = 0;
    ll j;
    while(i < 31){
        j = (1 << i);
        if(j == n){
            return true;
        }
        i++;
    }
    return false;
}
ll minK(int n){
    ll q = 0;
    ll j;
    for(int i = 30 ; i >= 0 ; --i){
        j = 1 << i;
        while(n >= j){
            n -= j;
            q++;
        }
    }
    return q;
}
void solve()
{
    int n , k ; 
    cin >> n >> k;
    if(k > n){
        cout << "NO\n";
        return;
    }
    if(k == 1 && !pow2(n)){
        cout << "NO\n";
        return;
    }
    if(k < minK(n)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> a;
    ll j;
    for(int i = 30 ; i >= 0 ; --i){
        j = 1 << i;
        while(n >= j){
            n -= j;
            a.pb(j);
            k--;
        }
        if(n == 0){
            break;
        }
    }
    sort(all(a));
    queue<int> q;
    int ptr = 0;
    if(k == 0){
        for(int i : a){
            cout << i << ' ';
        }
    }
    while(k > 0){
        if(a[ptr] == 1){
            q.push(a[ptr]);
            ptr++;
        }
        bool ck = 0;
        while(a[ptr] != 1 && k > 0){
            a[ptr] /= 2;
            q.push(a[ptr]);
            q.push(a[ptr]);
            k--;
            ck = 1;
        }
        if(ck){
            ptr++;
        }
    }
    for(int i = 0 ; i < q.size() ; i++){
        cout << q.front() << ' ';
        q.pop();
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