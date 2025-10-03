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

const int N  = 5e3 + 10;
vector<int> In[N];
vector<int> Out[N];
bool mark[N];


void dfs(int v){
    mark[v] = true;
    for(int i = 0 ; i < Out[v].size() ; ++i){
        int u = Out[v][i];
        if(!mark[u]){
            mark[u] = true;
            dfs(u);
        }
    }
}
bool mark2[N];
vector<int> w(N , 0);

void dfs2(int v,int par){
    if(mark[v]){
        return;
    }
    mark2[v] = true;
    for(int i = 0 ; i < Out[v].size() ; ++i){
        if(!mark2[Out[v][i]]){
            dfs2(Out[v][i] , par);
        }
    }
    w[par]++;
}
void solve()
{
    int n , m  , s;
    cin >> n >> m >> s;
    fo(i , m){
        int v, u;
        cin >> v >> u;
        Out[v].pb(u);
        In[u].pb(v);
    }
    dfs(s);
    int ans = 0;
    vector<int> best;
    for(int i = 1 ; i <= n ; ++i){
        if(In[i].size() == 0){
            best.pb(i);
        }
    }
    int t = best.size();
    for(int i = 0 ; i < t ; ++i){
       dfs2(best[i] , best[i]);
       memset(mark2 , false , sizeof mark2);
    }
    for(int i = 0 ; i < t - 1 ; ++i){
        for(int j = 0 ; j < t - i - 1 ; ++j){
            if(w[best[j + 1]] < w[best[j + 2]]){
                swap(best[j + 1] , best[j + 2]);
                swap(w[best[j + 1]] , w[best[j + 2]]);
            }
        }
    }
    for(int i = 0 ; i < t ; ++i){
        int v = best[i];
        if(!mark[v]){
            In[v].pb(s);
            Out[s].pb(v);
            dfs(v);
            ans++;
        }
    }
    if(In[s].size() == 0 && Out[s].size() == 0){
        ans++;
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}