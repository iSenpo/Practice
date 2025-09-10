#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size() -1;
    if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[n-2] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[n-3] == '2' && s[n-2] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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