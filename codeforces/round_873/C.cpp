#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (auto& i:a) cin >> i;
        for (auto& i:b) cin >> i;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        bool can = true;
        for (int i=0; i<n; ++i) {
            if (a[i]<=b[i]) {
                can = false;
                break;
            }
        }
        
        if (!can) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> v(n);
        v[0] = 1;
        for (int i=n-1; i>=1; --i) {
            int id = upper_bound(a.begin(),a.end(),b[i])-a.begin();
            v[i] = i-id+1;
        }
        constexpr int MOD = 1e9 + 7;
        int64_t ans = 1;
        for (int i=0; i<n; ++i) {
            ans *= v[i];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}

