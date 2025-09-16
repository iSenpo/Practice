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
    int a[n + 1];
    vector<pair<int,int>> v;
    vector<int> s(n + 1);
    s[0] = 0;
    vector<bool> p(n + 1,false);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        p[a[i]] = true;
        s[i] = i;
    }
    sort(all(s));
    vector<int> m;
    for(int i = 1 ; i <= n ; i++){
        if(!p[i]){
            m.push_back(i);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        pair<int , int> Max;
        int dis = 0;
        if(a[i] == 0){
            for(int j : m){
                if(j > a[i]){
                    if(dis < j - i){
                        dis = j - i;
                        Max = {i , j};
                    }
                }
                else{
                    if(dis < i - j){
                        dis = i - j;
                        Max = {j , i};
                    }
                }
            }
        }
        else if(a[i] != s[i]){
            if(a[i] > i){
                Max = {i , a[i]};
            }
            else{
                Max = {a[i] , i};
            }
        }
        v.push_back(Max);
    }
    vector<bool> mark(n + 1, false);
    for(auto i : v){
        for(int j = i.first ; j <= i.second ; j++){
            mark[j] = true;
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(mark[i]){
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