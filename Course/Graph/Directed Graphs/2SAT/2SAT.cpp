#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5 + 10;
vector<int> adj[2 * N][2];
int n , m;

void add_clause(int v , int u){
    if(v < 0)
        v = (-2 * v) - 1;
    else
        v = (2 * v) - 2;
    if(u < 0)
        u = (-2 * u) - 1;
    else
        u = (2 * u) - 2;

    int notv = (v ^ 1);
    int notu = (u ^ 1);
    adj[notv][0].push_back(u);
    adj[v][1].push_back(notu);
    adj[notu][0].push_back(v);
    adj[u][1].push_back(notv);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        add_clause(v , u);
    }
    return 0;
}
