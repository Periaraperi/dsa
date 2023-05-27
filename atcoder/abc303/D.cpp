#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int64_t x,y,z; cin >> x >> y >> z;
        string s; cin >> s;
        int n = (int)s.size();
        //dp[i][0]  = off
        //dp[i][1]  = on
        vector<vector<int64_t>> dp(n+1,vector<int64_t>(2));
        dp[0][0] = 0LL;
        dp[0][1] = z;
        for (int i=1; i<=n; ++i) {
            if (s[i-1]=='A') {
                dp[i][1] = min(dp[i-1][1]+x,min(dp[i-1][0]+z+x,dp[i-1][0]+y+z));
                dp[i][0] = min(dp[i-1][0]+y,min(dp[i-1][1]+x+z,dp[i-1][1]+z+y));
            } else {
                dp[i][0] = min(dp[i-1][0]+x,min(dp[i-1][1]+z+x,dp[i-1][1]+y+z));
                dp[i][1] = min(dp[i-1][1]+y,min(dp[i-1][0]+x+z,dp[i-1][0]+z+y));
            }
        }
        cout << min(dp[n][0],dp[n][1]) << '\n';
    }
    return 0;
}

