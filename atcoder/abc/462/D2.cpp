#include <iostream>
#include <vector>
#include <cstdint>

struct info {
    int s;
    int t;
};

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, d; std::cin >> n >> d;
    constexpr int MAXN {1000000};
    std::vector<int64_t> u(MAXN+1, 0);
    std::vector<info> v(n);
    for (auto& [s, t]:v)  {
        std::cin >> s >> t;
        if (t-s < d) continue;
        ++u[s];
        --u[t-d+1];
    }
    for (int i{1}; i<static_cast<int>(u.size()); ++i) {
        u[i] += u[i-1];
    }
    int64_t count {};
    for (int i{1}; i<=MAXN; ++i) {
        count += (u[i]*(u[i]-1)/2);
    }
    std::cout << count << '\n';

    return 0;
}


