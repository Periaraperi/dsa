#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 1e6;
    const int MOD = 1e9+7;
    int t; cin >> t;
    //precompute
    vector<vector<ll>> dp(N+1,vector<ll>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    // dp[i][0] = solution for tower with height i, where last domino is not linked
    // dp[i][1] = solution for tower with height i, where last domino is linked
    for(int i=1; i<N; ++i) {
        // 4 ways that not linked tile extends into not linked, and 1 way linked extends into not linked
        dp[i+1][0] += 4*dp[i][0]+dp[i][1];
        // 2 ways that linked extends into linked, and 1 way not linked extends into linked
        dp[i+1][1] += 2*dp[i][1]+dp[i][0];
        dp[i+1][0] %= MOD;
        dp[i+1][1] %= MOD;
    }

    while(t--) {
        int n; cin >> n;
        cout << (dp[n][0]+dp[n][1])%MOD << '\n';
    }

    return 0;
}