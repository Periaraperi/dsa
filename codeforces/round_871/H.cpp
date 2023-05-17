#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n+1);
        for (int i=1; i<=n; ++i) cin >> a[i];
        // dp[i][j] = number of ways to get j by bitwise and-ing of first i nums
        vector<vector<int64_t>> dp(n+1,vector<int64_t>(64)); 
        
        constexpr int MOD = 1e9 + 7;
        for (int i=1; i<=n; ++i) {
            ++dp[i][a[i]]; dp[i][a[i]] %= MOD;
            for (int j=0; j<64; ++j) {
                dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
                dp[i][a[i]&j] = (dp[i][a[i]&j]+dp[i-1][j])%MOD;
            }
        }

        int64_t ans = 0;
        for (int i=0; i<64; ++i) {
            int cnt = 0;
            for (int j=0; j<6; ++j) {
                if (i&(1<<j)) ++cnt;
            }
            if (cnt==k) {
                ans += dp[n][i];
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

