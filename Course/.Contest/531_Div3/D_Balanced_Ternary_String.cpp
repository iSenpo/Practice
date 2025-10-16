#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
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

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = n/3;
    int cnt[3] = {0 , 0 , 0};
    vector<int> ind[3];
    fo(i , n){
        if(s[i] == '0'){
            cnt[0]++;
        }
        if(s[i] == '1'){
            cnt[1]++;
        }
        if(s[i] == '2'){
            cnt[2]++;
        }
    }
    int i = 0;
    while(cnt[0] < m){
        if(s[i] == '2' && cnt[2] > m){
            s[i] = '0';
            cnt[2]--;
            cnt[0]++;
        }
        if(s[i] == '1' && cnt[1] > m){
            s[i] = '0';
            cnt[1]--;
            cnt[0]++;
        }
        i++;
    }
    i = n - 1;
    while(cnt[2] < m){
        if(s[i] == '1' && cnt[1] > m){
            s[i] = '2';
            cnt[1]--;
            cnt[2]++;
        }
        if(s[i] == '0' && cnt[0] > m){
            s[i] = '2';
            cnt[0]--;
            cnt[2]++;
        }
        --i;
    }
    int cnt0 = 0;
    fo(j , n){
        if(s[j] == '0'){
            cnt0++;
        }
        if(cnt0 == m){
            cnt0 = j + 1;
            break;
        }
    }
    i = cnt0;
    while(cnt[1] < m && i < n){
        if(s[i] == '0' && cnt[0] > m){
            s[i] = '1';
            cnt[1]++;
            cnt[0]--;
        }
        if(s[i] == '2' && cnt[2] > m){
            s[i] = '1';
            cnt[2]--;
            cnt[1]++;
        }
        i++;
    }
    int cnt2 = 0;
    for(int j = n - 1 ; j >= 0 ; j--){
        if(s[j] == '2'){
            cnt2++;
        }
        if(cnt2 == m){
            cnt2 = j + 1;
            break;
        }
    }
    i = cnt2;
    while(cnt[1] < m && i >= 0){
        if(s[i] == '0' && cnt[0] > m){
            s[i] = '1';
            cnt[1]++;
            cnt[0]--;
        }
        if(s[i] == '2' && cnt[2] > m){
            s[i] = '1';
            cnt[2]--;
            cnt[1]++;
        }
        i++;
    }
    cout << s << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow