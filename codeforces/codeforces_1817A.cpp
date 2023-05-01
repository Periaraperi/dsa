#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,q; cin >> n >> q;
        vector<int> v(n);
        for (auto& i:v) cin >> i;
        vector<int> pref(n-1);
        for (int i=1; i<n-1; ++i) {
            int x = 0;
            if (v[i]<=v[i-1] && v[i]>=v[i+1]) x = 1; // not including
            pref[i] = pref[i-1]+x;
        }

        while (q--) {
            int l,r; cin >> l >> r;
            --l; --r;
            if (l==r) cout << "1\n";
            else cout << (r-l+1)-(pref[r-1]-pref[l]) << '\n';
        }
    }
    return 0;
}

