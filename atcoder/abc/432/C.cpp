#include <iostream>
#include <vector>
#include <limits>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x, y; std::cin >> n >> x >> y;
    std::vector<int64_t> a(n);
    int64_t smallest {std::numeric_limits<int64_t>::max()};
    int64_t largest {};
    for (auto& i:a) {
        std::cin >> i;
        smallest = std::min(smallest, i);
        largest = std::max(largest, i);
    }
    const int64_t target_weight {smallest*y};
    if (largest*x > target_weight) {
        std::cout << -1 << '\n';
        return 0;
    }

    const int diff {y-x};
    int64_t ans {};
    for (int i{}; i<n; ++i) {
        if (((target_weight-x*a[i]) % diff) == 0) {
            const auto u {(target_weight-x*a[i])/diff};
            ans += u;
        }
        else {
            ans = -1;
            break;
        }
    }

    std::cout << ans << '\n';
    return 0;
}

