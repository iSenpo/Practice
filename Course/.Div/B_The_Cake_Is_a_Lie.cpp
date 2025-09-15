#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 100;
vector<vector<int>> grid(N , vector<int>(N , 0));

void solve(){
    int n , m , k;
    cin >> n >> m >> k;
    n--;
    m--;
    if(grid[n][m] == k){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    for(int i = 1 ; i < N ; i++){
        grid[0][i] = grid[0][i-1] + 1;
    }
    for(int i = 1 ; i < N ; i++){
        grid[i][0] = grid[i-1][0] + 1;
    }
    for(int i = 1 ; i < N ; i++){
        for(int j = 1 ; j < N ; j++){
            grid[i][j] = grid[i][j-1] + i + 1;
        }
    }
    while(t--){
        solve();
    }
    return 0;
}