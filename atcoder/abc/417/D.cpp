#include <iostream>
#include <vector>
 
using namespace std;

struct info {
    int p{};
    int a{};
    int b{};
};

// j = inital mood
// i = suffix in presents array
// dp[N][j] = j+An or j-Bn
// dp[N-1][j] = dp[N][j+B(n-1)] or dp[N][j+A(n-1)]
//
//
// dp[i][j] = dp[i+1][j+ai] or dp[i+1][j-bi] or (j+An or j-Bn if i == n)
// ^
// |
// will tell me state for suffix of presents with initial mood less than or equal to 500
// if X is more than 500, we need to take L-lengthed prefix from presents and decrease by prefix_sum(Bi)

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<info> v(n);
    vector<int64_t> pref_sum_b(n+1);
    for (auto& [p, a, b]:v) {
        cin >> p >> a >> b;
    }
    v.insert(v.begin(), info{});

    for (int i{1}; i<=n; ++i) {
        pref_sum_b[i] = pref_sum_b[i-1]+v[i].b;
    }
    constexpr int MAX_MOOD {1000};
    vector<vector<int>> dp(n+1, vector<int>(MAX_MOOD+1)); // 1000 because of 500+500

    // base case:
    for (int initial_mood{}; initial_mood<=1000; ++initial_mood) {
        if (v[n].p >= initial_mood) {
            dp[n][initial_mood] = initial_mood+v[n].a;
        }
        else {
            dp[n][initial_mood] = max(initial_mood-v[n].b, 0);
        }
    }
    for (int suff=n-1; suff>=1; --suff) {
        for (int mood{}; mood<=1000; ++mood) {
            if (v[suff].p >= mood) {
                dp[suff][mood] = dp[suff+1][mood+v[suff].a];
            }
            else {
                dp[suff][mood] = dp[suff+1][max(mood-v[suff].b, 0)];
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int64_t x; cin >> x;
        if (x<=MAX_MOOD) {
            cout << dp[1][x] << '\n';
            continue;
        }

        // if x is big, get the smallest prefix in presents so that x becomes in "good" range
        int l{1}, r{n};
        while (l <= r) {
            int m {(l+r)/2};
            auto mood {x-pref_sum_b[m]};
            if (mood < 0) mood = 0;
            if (mood <= MAX_MOOD) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        if (l >= n) {
            cout << x-pref_sum_b[n] << '\n';
        }
        else {
            cout << dp[l+1][x-pref_sum_b[l]] << '\n';
        }
    }
    return 0;
}

