#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector g(n, vector<bool>(n, false));
    for (int i{}; i<m; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        if (a > b) swap(a, b);
        g[a][b] = true;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    int ans {1000000};
    do {
        int cost {};
        vector gr(n, vector<bool>(n, false));
        for (int i{}; i<n; ++i) {
            int a {p[i]};
            int b {p[(i+1)%n]};
            if (a > b) swap(a, b);
            gr[a][b] = true;
        }
        for (int i{}; i<n; ++i) {
            for (int j{}; j<n; ++j) {
                if (gr[i][j] != g[i][j]) {
                    ++cost;
                }
            }
        }
        ans = min(ans, cost);
        // possible 2 components in the answer
        for (int d{3}; d<=n-3; ++d) {
            for (int i{}; i<n; ++i) {
                for (int j{}; j<n; ++j) {
                    gr[i][j] = false;
                }
            }
            cost = 0;
            vector<int> left;
            vector<int> right;
            for (int i{}; i<d; ++i) {
                left.emplace_back(p[i]);
            }
            for (int i{d}; i<n; ++i) {
                right.emplace_back(p[i]);
            }
            for (const auto& v: {left, right}) {
                for (int i{}; i<(int)v.size(); ++i) {
                    int a {v[i]};
                    int b {v[(i+1)%(int)v.size()]};
                    if (a > b) swap(a, b);
                    gr[a][b] = true;
                }
            }
            for (int i{}; i<n; ++i) {
                for (int j{}; j<n; ++j) {
                    if (gr[i][j] != g[i][j]) {
                        ++cost;
                    }
                }
            }
            ans = min(ans, cost);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';

    return 0;
}
