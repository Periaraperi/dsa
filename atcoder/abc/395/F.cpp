#include <iostream>
#include <limits>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    struct info {
        int u{};
        int d{};
    };
    vector<info> v(n);
    for (auto& [u, d]:v) cin >> u >> d;

    int64_t ans{};

    { // if abs value rule is broken we need to grind upper teeth. So fix all upper teeth to optimal values first.
        for (int i{}; i<n-1; ++i) {
            if (abs(v[i].u-v[i+1].u) > x) {
                if (v[i].u > v[i+1].u) {
                    ans += (v[i].u - (v[i+1].u+x));
                    v[i].u = (v[i+1].u+x);
                }
                else {
                    ans += (v[i+1].u - (v[i].u+x));
                    v[i+1].u = (v[i].u+x);
                }
            }
        }
        // go backwards to 'fix' good ones that became bad
        for (int i{n-1}; i>0; --i) {
            if (abs(v[i].u-v[i-1].u) > x) {
                if (v[i].u > v[i-1].u) {
                    ans += (v[i].u - (v[i-1].u+x));
                    v[i].u = (v[i-1].u+x);
                }
                else {
                    ans += (v[i-1].u - (v[i].u+x));
                    v[i-1].u = (v[i].u+x);
                }
            }
        }
    }

    // since teeth only get smaller I need the sum of U and D to be min(ui+di)
    int h {numeric_limits<int>::max()};
    for (auto& [u, d]:v) {
        h = min(h, u+d);
    }

    for (auto& [u, d]:v) {
        if (u+d == h) continue;
        ans += (u+d-h);
    }
    cout << ans << '\n';

    return 0;
}

