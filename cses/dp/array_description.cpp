#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    vector<vector<int>> dp(n,vector<int>(m+1));
    if(v[0]==0) for(int x=1; x<=m; ++x) dp[0][x] = 1;
    else dp[0][v[0]] = 1;

    const int mod = 1e9+7;
    for(int i=1; i<n; ++i)
    {
        if(v[i]==0)
        {
            for(int j=1; j<=m; ++j)
            {
                for(int k:{j-1,j,j+1})
                {
                    if(k>=1 && k<=m)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        else
        {
            for(int j:{v[i]-1,v[i],v[i]+1})
            {
                if(j>=1 && j<=m)
                    dp[i][v[i]] = (dp[i][v[i]]+dp[i-1][j])%mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1; i<=m; ++i)
        ans = (ans+dp[n-1][i])%mod;
    cout << ans;
}
