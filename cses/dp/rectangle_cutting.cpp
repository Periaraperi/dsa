#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b; cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    for (int i=1; i<=a; ++i) {
        for (int j=1; j<=b; ++j) {
            if (i==j) {
                dp[i][j] = 0;
                continue;
            }
            dp[1][j] = j-1;
        }
        dp[i][1] = i-1;
    }
    for (int i=1; i<=a; ++i) {
        for (int j=1; j<=b; ++j) {
            if (i==j || i==1 || j==1) continue;
            for (int k=1; k<=i-1; ++k) 
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            for (int k=1; k<=j-1; ++k) 
                dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}

