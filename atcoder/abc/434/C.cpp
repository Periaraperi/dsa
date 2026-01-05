#include <iostream>
#include <vector>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t{1}; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        int64_t h; std::cin >> h;
        struct info {
            int64_t a {};
            int64_t b {};
            int64_t c {};
        };
        std::vector<info> v(n);
        int64_t curr_t {};
        int64_t curr_l {h};
        int64_t curr_r {h};
        for (auto& [a, b, c]:v) {
            std::cin >> a >> b >> c;
        }
        bool ok {true};
        for (const auto& [a, b, c]:v) {
            const auto l {std::max(std::max(curr_l-(a-curr_t), 1L), b)};
            const auto r {std::min(curr_r+(a-curr_t), c)};
            if (l > r) {
                ok = false;
                break;
            }
            curr_t = a;
            curr_l = l;
            curr_r = r;
        }
        if (ok) std::cout << "Yes\n";
        else    std::cout << "No\n";
    }
    return 0;
}

