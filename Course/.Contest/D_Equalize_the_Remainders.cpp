#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(ll i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)


inline ll in(){
    ll x;
    cin >> x;
    return x;
}
void solve()
{
    ll n = in();
    ll k = in();
    ll a[n];
    fo(i , n){
        cin >> a[i];
    }
    vector<ll> v[k];
    vector<pair<ll , ll>> Rm(k , pair<ll , ll>({0 , 0}));
    for(ll i = 0 ; i < n ; ++i){
        ll ind = a[i]%k;
        v[ind].pb(i);
        Rm[ind].first++;
        Rm[ind].second = ind;
    }
    sort(all(Rm));
    ll ptr = k - 1;
    ll ptl = 0;
    ll m = n/k;
    ll ans = 0;
    while(ptl <= ptr){
        while(Rm[ptl].first < m && Rm[ptr].first > m){
            ll i = Rm[ptr].second;
            ll j = Rm[ptl].second;
            ll ind = v[i][v[i].size() - 1];
            v[i].pop_back();
            v[j].push_back(ind);
            ll diff = (j - (a[ind] % k) + k) % k;
            a[ind] += diff;
            ans += diff;
            Rm[ptl].first++;
            Rm[ptr].first--;
        }
        if(Rm[ptl].first == m){
            ptl++;
        }
        if(Rm[ptr].first == m){
            ptr--;
        }
    }
    cout << ans << ln;
    for(ll i = 0 ; i < n ; ++i){
        cout << a[i] << ' '; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    ll t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}