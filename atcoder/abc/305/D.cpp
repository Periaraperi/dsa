#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i:v) cin >> i;
        vector<int64_t> pref(n);
        for (int i=2; i<n; i+=2) {
            pref[i] = pref[i-1]+(v[i]-v[i-1]);
        }
        for (int i=1; i<n; ++i) pref[i] += pref[i-1];

        //for (int i=0; i<n; ++i) cout << pref[i] << " ";
        //cout << '\n';


        int q; cin >> q;
        while (q--) {
            int l,r; cin >> l >> r;
            int rr = lower_bound(v.begin(),v.end(),r)-v.begin();
            int ll = lower_bound(v.begin(),v.end(),l)-v.begin();
            int64_t ans = pref[rr]-pref[ll];
            if (rr%2==0) ans -= (v[rr]-r);
            if (ll%2==0) ans += (v[ll]-l);
            cout << ans << '\n';
        }
    }
    return 0;
}

