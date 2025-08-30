#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int INF {1000000000};

    int n, m, l; cin >> n >> m >> l;

    vector<int> a(n);
    for (auto& i:a) cin >> i;

    // if all l-lengthed subarrays' sums are divisible by m
    // we know that ai is congruent to a(i+l)mod m. Likewise a(i+l) is congruent to a(i+2l)mod m. And so on...
    // ai is congruent to a(i+kl)mod m, where k is positive integer

    // we can calculate min number of increments needed,
    // to get remainder of R when dividing ai, a(i+l), a(i+2l) and so on by M
    // cost[i][r] = min num of increments such that all elements ai with same mod (i mod L) has remainder of r
    // when dividing by m (r ranges from 0 to m-1)
    vector cost(n, vector<int>(m, 0));
    for (int i{}; i<n; ++i) {
        for (int rem{}; rem<m; ++rem) {
            if (a[i] % m == rem) continue;
            if (a[i] < rem) cost[i][rem] = rem-a[i];
            else {
                const auto x {a[i]/m + 1};
                cost[i][rem] = ((x*m + rem) - a[i]);
            }
        }
    }
    // suffix sum to avoid another nest loop above
    for (int rem{}; rem<m; ++rem) {
        for (int i{n-1}; i>=0; --i) {
            if (i+l < n) {
                cost[i][rem] += cost[i+l][rem];
            }
        }
    }

    // dp[i][r] = min number of increments, such that sum of first i elements has remainder of r when divided by m.
    // here since cost table has cumulative sums, dp[i][r] will count increments for all "same colored" elements.
    // so we only need to iterate i till l.
    vector dp(l, vector<int>(m, INF));
    // base case
    for (int i{}; i<m; ++i) dp[0][i] = cost[0][i];

    for (int i{}; i+1<l; ++i) {
        for (int r1{}; r1<m; ++r1) {
            for (int r2{}; r2<m; ++r2) {
                dp[i+1][(r1+r2)%m] = min(dp[i+1][(r1+r2)%m], dp[i][r1]+cost[i+1][r2]);
            }
        }
    }
    cout << dp[l-1][0] << '\n';
    return 0;
}

