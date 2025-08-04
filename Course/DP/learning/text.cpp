#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n , m;
vector<vector<char>> a;
vector<vector<int>> dp;
const int INF = 1e6;

int solve(int i ,int j){
    //base:
    if(i == n-1 && j == m-1){
        return 1;
    }
    if(i >= n || j >= m){
        return 0;
    }
    // transition:
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = solve(i , j + 1) + solve(i + 1 , j);

    return dp[i][j];
}
int main(){
    cin >> n >> m;

    a.resize(n , vector<char>(m));
    dp.resize(n + 1 , vector<int>(m + 1 , -1));

    bool mark = false;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                mark = true;
            }
            if(mark){
                dp[i][j] = 0;
            }
        }
        mark = false;
    }
    cout << solve(0 , 0)<< endl;
    return 0;
}
//