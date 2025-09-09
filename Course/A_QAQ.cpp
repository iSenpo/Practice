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

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0 ; i< s.size(); i++){
        if(s[i] == 'Q'){
            for(int j = i + 1 ; j < s.size(); j++){
                if(s[j] == 'A'){
                    for(int k = j + 1 ; k < s.size(); k++){
                        if(s[k] == 'Q'){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout << sum << ln;
    return 0;
}