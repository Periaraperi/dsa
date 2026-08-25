#include <iostream>
#include <vector>
#include <cstdint>

namespace peria {

template<std::integral T>
struct fenwick {
    explicit fenwick(std::size_t n)
        :v(std::vector<T>(n+1, 0))
    {}

    void update(int i, T increment)
    {
        if (i == 0) return;
        while(i < static_cast<int>(v.size())) {
            v[i] += increment;
            i += (i&-i);
        }
    }

    [[nodiscard]]
    T query(int i) // sum from [0, i]
    {
        T sum {};
        while(i > 0) {
            sum += v[i];
            i -= (i&-i);
        }
        return sum;
    }

private:
    std::vector<T> v;
};

}

struct info {
    int s;
    int t;
};

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, d; std::cin >> n >> d;
    std::vector<info> v(n);
    for (auto& [s, t]:v) std::cin >> s >> t;
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.s < b.s; });
    constexpr int MAXN {1000000};
    peria::fenwick<int64_t> ft{2*MAXN+1};
    int64_t count {};
    int k {};
    for (int i{1}; i<=MAXN; ++i) {
        const int j {i+d};
        while (k < static_cast<int>(v.size()) && v[k].s <= i) {
            ft.update(v[k].t, 1);
            ++k;
        }
        const auto c {ft.query(2*MAXN)-ft.query(j-1)};
        count += (c*(c-1))/2;
    }
    std::cout << count << '\n';

    return 0;
}

