#include <bits/stdc++.h>
using namespace std;

const int N  = 1e2 + 500;
vector<int> adj[N] , ind[N] , ans;
bool mark[N];
int ptr[N];

void tour(int v){
    while(ptr[v] < adj[v].size()){
        int u = adj[v][ptr[v]];
        int index = ind[v][ptr[v]];
        ptr[v]++;
        if(!mark[index]){
            mark[index] = true;
            tour(u);
        }
    }
    ans.push_back(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n;
    pair<int , int> domino[n];
    for(int i = 0 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        v-- ; u--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ind[u].push_back(i);
        ind[v].push_back(i);
        domino[i] = {v , u};
    }
    tour(0);
    for(int i = 0 ; i < ans.size() - 1 ; i+=2){
        int v = ans[i];
        int u = ans[i+1];
        for(int j = 0 ; j < n ; j++){
            if(v == domino[j].first && u == domino[j].second){
                cout << j + 1 << '+' << endl;
                domino[j].first = 0;
                domino[j].second = 0;
                break;
            }
            if(u == domino[j].first && v == domino[j].second){
                cout << j + 1 << '-' << endl;
                domino[j].first = 0;
                domino[j].second = 0;
                break;
            }
        }
    }
    return 0;
}