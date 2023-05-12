#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vector<int64_t> v(n);
        int64_t sm = 0;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            sm += v[i];
        }

        //cout << "sm " << sm << '\n';
        sort(v.begin(),v.end());
        vector<int64_t> pref = v;
        vector<int64_t> suff = v;
        for (int i=1; i<n; ++i) pref[i] += pref[i-1];
        for (int i=n-2; i>=0; --i) suff[i] += suff[i+1];
        reverse(suff.begin(),suff.end());
        pref.insert(pref.begin(),0);
        suff.insert(suff.begin(),0);
        //for (auto i:pref) cout << i <<" ";
        //cout << '\n';
        //for (auto i:suff) cout << i << " ";
        //cout << '\n';

        int64_t ans = 0;
        for (int i=0; i<=k; ++i) {
            int x = k-i;
            ans = max(ans,sm-(pref[2*i]+suff[x]));
        }
        cout << ans << '\n';
    }
    return 0;
}

