#include <bits/stdc++.h>
using namespace std;

//Shayan Erfanian 
//40311126044

int n , m;
vector<vector<int>> matrix;
vector<vector<bool>> mark;
bool isOk(int x , int y){
    if(x >= n || y >= m || x < 0 || y < 0){
        return false;
    }
    if(mark[x][y] == true){
        return false;
    }
    if(matrix[x][y] == 1){
        return false;
    }
    return true;
}
const int dx[4] = {1 , 0 , -1 , 0};
const int dy[4] = {0 , 1 , 0 , -1};

int main(){
    cin >> n >> m;
    matrix.resize(n + 2 , vector<int>(m + 2));
    mark.resize(n + 2 , vector<bool>(m + 2 , false));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> matrix[i][j];
        }
    }

    stack<pair<int , int>> st;
    st.push({0 , 0});
    mark[0][0] = true;

    while(!st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        mark[x][y] = true;
        if(x == n - 1 && y == m - 1){
            break;
        }
        bool deadEnd = true;
        for(int i = 0 ; i < 4 ; i++){
            if(isOk(x + dx[i] , y + dy[i])){
                mark[x + dx[i]][y + dy[i]] = true;
                st.push({x + dx[i] , y + dy[i]});
                deadEnd = false;
                break;
            }
        }
        if(deadEnd){
            st.pop();
        }
    }
    vector<pair<int , int>> path;
    int t = st.size();
    for(int i = 0 ; i < t ; i++){
        path.push_back(st.top());
        st.pop();
    }
    reverse(path.begin() , path.end());
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    for(int i = 0 ; i < t ; i++){
        cout << "(" << path[i].first << " , " << path[i].second << ") ";
    }
}
