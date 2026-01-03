#include <iostream>
#include <vector>

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

constexpr int NMAX {500000 + 10};

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> v(n);
    int zero {};
 
    for (auto& i:v) {
        std::cin >> i;
        if (i == 0) ++zero;
    }
    
    peria::fenwick<int64_t> a{NMAX};
    peria::fenwick<int64_t> b{NMAX};
    for (const auto& i:v) {
        a.update(i, 1);
        b.update(i, i);
    }

    while (q--) {
        int op; std::cin >> op;
        if (op == 1) {
            int x, y; std::cin >> x >> y;
            --x;
            const auto old {v[x]};
            a.update(old, -1);
            a.update(y, 1);
            if (old == 0) --zero;
            if (y == 0) ++zero;
            b.update(old, -old);
            b.update(y, y);
            v[x] = y;
        }
        else {
            int l, r; std::cin >> l >> r;
            if (l > r) {
                std::cout << static_cast<int64_t>(l)*static_cast<int64_t>(n) << '\n';
            }
            else {
                const auto less_or_eq_l {a.query(l)};
                const auto more_or_eq_r {a.query(NMAX)-a.query(r-1)};
                const auto sum_in_between {b.query(r-1)-b.query(l+1-1)};
                std::cout << (less_or_eq_l+zero)*static_cast<int64_t>(l) + more_or_eq_r*static_cast<int64_t>(r) + sum_in_between << '\n';
            }
        }
    }
    return 0;
}

