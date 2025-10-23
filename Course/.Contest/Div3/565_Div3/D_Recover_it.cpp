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

const int N  = 2750135;
//always check input!!!
bool not_prime[N];
vector<int> primes;

void primeFinder(){
    for(int i = 2; i <= N ; ++i){
        if(!not_prime[i]){
            primes.pb(i);
            for(int j = i * 2 ; j <= N ; j += i){
                not_prime[j] = 1;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    vector<bool> mark(n , false);
    vector<int> ans;
    sort(a , a + n);
    fo(i , n){
        if(not_prime[a[i]]){
            int k;
            fo(j , 200000){
                if(a[i]%primes[j] == 0){
                    k = a[i] / primes[j];
                    break;
                }
            }
            ans.pb(a[i]);
            mark[i] = true;
            int up = n - 1;
            int dw = 0;
            int mid = (up + dw)/2;
            while(up >= dw){
                mid = (up + dw)/2;
                if(a[mid] == k && !mark[mid]){
                    mark[mid]; 
                    break;
                }
                else if(a[mid] > k){
                    up = mid - 1;
                }
                else {
                    dw = mid + 1;
                }
            }
        }
    }
    fo(i , n){
        if(!mark[i]){
            ans.pb(a[i]);
            int k = primes[a[i]];
            int up = n - 1;
            int dw = 0;
            int mid = (up + dw)/2;
            while(up >= dw){
                mid = (up + dw)/2;
                if(a[mid] == k && !mark[mid]){
                    mark[mid]; 
                    break;
                }
                else if(a[mid] > k){
                    up = mid - 1;
                }
                else {
                    dw = mid + 1;
                }
            }
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        primeFinder();
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow