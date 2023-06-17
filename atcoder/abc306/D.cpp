#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int,int64_t>> v(n);
        for (auto& [x,y]:v) {
            cin >> x >> y;
        }

        vector<vector<int64_t>> dp(n+1,vector<int64_t>(2));
        for (int i=1; i<=(int)v.size(); ++i) {
            auto [x,y] = v[i-1];

            if (x==0) {
                dp[i][0] = max(dp[i-1][0],dp[i-1][0]+y);
                dp[i][0] = max(dp[i][0],y);
                dp[i][0] = max(dp[i][0],dp[i-1][1]+y);

                dp[i][1] = dp[i-1][1];

            } else {
                dp[i][1] = max(dp[i-1][0]+y,dp[i-1][1]);
                dp[i][1] = max(dp[i][1],y);

                dp[i][0] = dp[i-1][0];
            }

        }
        cout << max(dp[n][0],dp[n][1]) << '\n';
    }
    return 0;
}

