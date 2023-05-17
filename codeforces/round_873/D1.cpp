#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i:a) 
            cin >> i;
        
        int64_t ans = (1LL*n*(n-1)*(n+1))/6; // initial answer where 'good' split points are absent

        // precalculate mins on semi intervals
        constexpr int INF = 1e9 + 100;
        vector<vector<int>> mn(n+1,vector<int>(n+1,INF));
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<=n; ++j) {
                mn[i][j] = min(mn[i][j-1],a[j-1]);
            }
        }

        // if index k is 'good' split point, count in how many subarrays does it contribute to
        for (int k=0; k<n; ++k) {
            int mx = -INF;
            int r = n;
            for (int l=k-1; l>=0; --l) {
                mx = max(mx,a[l]);
                while (mx>mn[k][r]) --r;
                ans -= (r-k);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

