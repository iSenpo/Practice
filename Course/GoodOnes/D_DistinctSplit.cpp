#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<char> st;
        vector<int> prefix(n+1 , 0);
        vector<int> suffix(n+1 , 0);
        for(int i = 0; i < n ; i++){
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        st.clear();
        for(int i = n -1; i >= 0; i--){
            st.insert(s[i]);
            suffix[i] = st.size();
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
            ans = max(ans , prefix[i] + suffix[i+1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
