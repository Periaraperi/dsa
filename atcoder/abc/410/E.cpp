#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m; cin >> n >> h >> m;
    vector<int> a(n+1), b(n+1);
    for (int i{1}; i<=n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector dp(n+1, vector<int>(m+1, -1));
    for (int i{}; i<=m; ++i) {
        dp[0][m] = h;
    }

    for (int i{1}; i<=n; ++i) {
        for (int j{}; j<=m; ++j) {
            dp[i][j] = dp[i-1][j]-a[i];
            if (j+b[i]<=m) {
                dp[i][j] = max(dp[i][j], dp[i-1][j+b[i]]);
            }
        }
    }

    int rounds_won {};
    for (int i{1}; i<=n; ++i) {
        bool ok {false};
        for (int j{}; j<=m; ++j) {
            if (dp[i][j] >= 0) {
                ok = true;
                break;
            }
        }
        if (ok) ++rounds_won;
        else break;
    }
    cout << rounds_won << '\n';

    return 0;
}

