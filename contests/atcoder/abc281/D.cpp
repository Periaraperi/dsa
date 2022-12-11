#include <bits/stdc++.h>

using namespace std;

/*
    Nice problem
    Similar to knapsack
    with some modifications
    Learned something new :)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n,k,d; cin >> n >> k >> d;
        vector<long long> v(n);
        for (auto& i:v) cin >> i;
        
        auto INF = numeric_limits<long long>::min();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(k+1,vector<long long>(d,-INF)));
        dp[0][0][0] = 0;
        for (int i=1; i<=n; ++i)
            dp[i][0][0] = 0;

        for (int i=1; i<=n; ++i) {
            for (int kk=1; kk<=min(i,k); ++kk) {
                for (int rem=0; rem<d; ++rem) {
                    dp[i][kk][rem] = dp[i-1][kk][rem];
                    
                    dp[i][kk][rem] = max(dp[i][kk][rem],
                                         dp[i-1][kk-1][((rem-(v[i-1]%d))+d)%d]+v[i-1]);
                }
            }
        }
        if (dp[n][k][0]<0) cout << "-1\n";
        else               cout << dp[n][k][0] << '\n';
    }
    return 0;
}