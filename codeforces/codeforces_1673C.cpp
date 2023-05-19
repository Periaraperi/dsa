#include <bits/stdc++.h>
 
using namespace std;

bool palindromic(int n)
{
    int a = n;
    int m = 0;
    while (a>0) {
        m *= 10;
        m += (a%10);
        a /= 10;
    }
    return m==n;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    vector<int> palindromics;
    int N = 4e4;
    vector<bool> pal(N+1);
    vector<int> dp(N+1);
    for (int i=1; i<=N; ++i) {
        if (palindromic(i)) {
            palindromics.push_back(i);
            pal[i] = true;
        }
    }
    constexpr int MOD = 1e9 + 7;

    dp[0] = 1;
    for (int j=0; j<palindromics.size(); ++j) {
        for (int i=1; i<=N; ++i) {
            int x = i-palindromics[j];
            if (x>=0) {
                dp[i] += dp[x];
                dp[i] %= MOD;
            }
        }
    }

    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}

