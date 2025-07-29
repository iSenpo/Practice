#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int n , m;
    cin >> n >> m;
    int s = n * m ;
    if(s%2 == 0){
        cout << s/2 ;
    }
    else{
        cout << (s + 1 )/2 -1 ;
    }
    return 0;
}