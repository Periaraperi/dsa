#include <iostream>
#include <vector>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    struct info {
        int w {};
        int64_t h {};
        int64_t b {};
    };
    std::vector<info> v(n);
    int total_w {};
    for (auto& [w, h, b]:v) {
        std::cin >> w >> h >> b;
        total_w += w;
    }
    const auto t {total_w/2};
    v.insert(v.begin(), info{});

    // dp[i][wh] = MAX happiness achieved with first i items with wh for head, max weight for head will be total_w / 2
    std::vector dp(v.size()+1, std::vector<int64_t>(t+1, 0));
    for (int i{1}; i<=n; ++i) {
        dp[i][0] = dp[i-1][0]+v[i].b; // we only use parts on body for wh = 0
    }
    for (int i{1}; i<=n; ++i) {
        const auto w {v[i].w};
        for (int j{}; j<=t; ++j) {
            int64_t t1 {};
            if (j-w >= 0) t1 = dp[i-1][j-w]+v[i].h; // use i-th on the head
            dp[i][j]= std::max(dp[i][j], std::max(dp[i-1][j]+v[i].b /*use i-th on the body*/, t1));
        }
    }
    int64_t ans {};
    for (int i{}; i<=t; ++i) {
        ans = std::max(ans, dp[n][i]);
    }
    std::cout << ans << '\n';

    return 0;
}

