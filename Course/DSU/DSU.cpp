#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int par[N] , Rank[N];

int find(int v){
    if(par[v] == -1)
        return v;
    return find(par[v]);
}

void merge(int v , int u){
    v = find(v);
    u = find(u);
    if(v == u)
        return;
    if(Rank[u] > Rank[v])
        swap(u , v);
    par[u] = v;
    Rank[v] = max(Rank[v] , Rank[u] + 1);
}
int main(){
    int n , q;
    memset(par , -1 , sizeof par);
    cin >> n >> q;
    while(q--){
        string question;
        int v , u;
        cin >> question >> v >> u;
        if(question == "edge"){
            merge(v , u);
        }
        if(question == "?"){
            if(find(u) == find(v)){
                cout << "Same set\n";
            }
            else{
                cout << "Disjoint set\n";
            }
        }
    }
    return 0;
}