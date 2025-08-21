#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t N;
    int M;
    cin >> N >> M;
    struct Info {
        int64_t a{};
        int64_t b{};
    };
    vector<Info> v(M);
    for (auto& [a, b]:v) {
        cin >> a >> b;
    }
    sort(v.begin(), v.end(), [](auto x, auto y) {
        const auto diff_x {x.a - x.b};
        const auto diff_y {y.a - y.b};
        if (diff_x == diff_y) {
            return x.a < y.a;
        }
        return diff_x < diff_y;
    });

    int64_t ans{};
    for (int i{}; i<M; ++i) {
        const auto& info {v[i]};
        const auto diff {info.a - info.b};
        if (N>=info.a) {
            const auto k {(N-info.a)/diff + 1};
            ans += k;
            N -= k*diff;
        }
    }
    cout << ans << '\n';
    return 0;
}

