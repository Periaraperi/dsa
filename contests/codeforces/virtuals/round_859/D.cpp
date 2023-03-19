#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,q; cin >> n >> q;
        vector<int> v(n);
        vector<long long> pref(n+1);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        for (int i=1; i<=n; ++i) {
            pref[i] = pref[i-1] + v[i-1];
        }
        
        while (q--) {
            int l,r,k; cin >> l >> r >> k;
            long long sm = pref[l-1] + (pref[n]-pref[r]) + (long long)(r-l+1)*k;
            if (sm%2==1) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}

