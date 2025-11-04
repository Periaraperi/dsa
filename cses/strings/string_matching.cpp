#include <iostream>
#include <vector>

namespace peria {

template<int M>
struct modint;

using mint = modint<998244353>;

template<int M>
[[nodiscard]] constexpr modint<M> bin_pow(modint<M> a, int64_t b)
{
    modint<M> res{1};
    while (b>0) {
        if (b%2 == 1) res *= a;
        a = a*a;
        b /= 2;
    }
    return res;
}

template<int M>
struct modint {
    static constexpr int MOD = M;
    constexpr modint() noexcept :value_{0} {}
    constexpr explicit modint(int64_t x) noexcept :value_{static_cast<int>(((x%M)+M)%M)} {}

    [[nodiscard]] constexpr modint operator-() const noexcept
    { return modint{-value_}; }

    [[nodiscard]] constexpr modint operator+(const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(value_)+static_cast<int64_t>(rhs.value_))%M}; }

    [[nodiscard]] constexpr modint operator-(const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(value_)-static_cast<int64_t>(rhs.value_)+M)%M}; }

    [[nodiscard]] constexpr modint operator*(const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(value_)*static_cast<int64_t>(rhs.value_))%M}; }

    constexpr modint& operator+=(const modint& rhs) noexcept
    { value_ = (static_cast<int64_t>(value_)+static_cast<int64_t>(rhs.value_))%M; return *this; }

    constexpr modint& operator+=(int64_t x) noexcept
    { auto y {modint<M>{x}}; return (*this+=y); }

    constexpr modint& operator-=(const modint& rhs) noexcept
    { value_ = (static_cast<int64_t>(value_)-static_cast<int64_t>(rhs.value_)+M)%M; return *this; }

    constexpr modint& operator-=(int64_t x) noexcept
    { auto y {modint<M>{x}}; return (*this-=y); }

    constexpr modint& operator*=(const modint& rhs) noexcept
    { value_ = (static_cast<int64_t>(value_)*static_cast<int64_t>(rhs.value_))%M; return *this; }

    constexpr modint& operator*=(int64_t x) noexcept
    { auto y {modint<M>{x}}; return (*this*=y); }

    [[nodiscard]] friend constexpr modint operator+(const modint& lhs, const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(lhs.value_)+static_cast<int64_t>(rhs.value_))%M}; }

    [[nodiscard]] friend constexpr modint operator+(int64_t x, const modint& rhs) noexcept
    { return modint{x}+rhs; }

    [[nodiscard]] friend constexpr modint operator+(const modint& lhs, int64_t x) noexcept
    { return lhs+modint{x}; }

    [[nodiscard]] friend constexpr modint operator-(const modint& lhs, const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(lhs.value_)-static_cast<int64_t>(rhs.value_)+M)%M}; }

    [[nodiscard]] friend constexpr modint operator-(int64_t x, const modint& rhs) noexcept
    { return modint{x}-rhs; }

    [[nodiscard]] friend constexpr modint operator-(const modint& lhs, int64_t x) noexcept
    { return lhs-modint{x}; }

    [[nodiscard]] friend constexpr modint operator*(const modint& lhs, const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(lhs.value_)*static_cast<int64_t>(rhs.value_))%M}; }

    [[nodiscard]] friend constexpr modint operator*(int64_t x, const modint& rhs) noexcept
    { return modint{x}*rhs; }

    [[nodiscard]] friend constexpr modint operator*(const modint& lhs, int64_t x) noexcept
    { return lhs*modint{x}; }

    [[nodiscard]] friend constexpr bool operator==(const modint& lhs, const modint& rhs) noexcept
    { return lhs.value_ == rhs.value_; }

    [[nodiscard]] friend constexpr bool operator!=(const modint& lhs, const modint& rhs) noexcept
    { return !(lhs == rhs); }

    [[nodiscard]] constexpr int value() const noexcept 
    { return value_; }

    [[nodiscard]] constexpr modint inverse() noexcept
    { return bin_pow(*this, M-2); }

private:
    int value_ {};
};

template<int M, int P>
struct rolling_hash_powers {
    explicit rolling_hash_powers(const std::size_t size)
        :p(size), p_inv(size)
    {
        p[0] = mint{1};
        p_inv[0] = p[0].inverse();
        for (std::size_t i{1}; i<size; ++i) {
            p[i] = p[i-1]*P;
            p_inv[i] = p[i].inverse();
        }
    }

    std::vector<peria::modint<M>> p;
    std::vector<peria::modint<M>> p_inv;
};

// polynomial rolling hash
struct rolling_hash {
    template<int M, int P>
    rolling_hash(const std::string& s, const rolling_hash_powers<M, P>& powers)
        :h(s.size()+1)
    {
        for (std::size_t i{}; i<s.size(); ++i) {
            h[i+1] = h[i] + (powers.p[i]*char_ascii_value(s[i]));
        }
    }

    [[nodiscard]]
    static int char_ascii_value(unsigned char character) noexcept
    { return static_cast<int>(character)+1; }

    // range indices are 1-based
    template<int M, int P>
    [[nodiscard]] int sub_hash(std::size_t i, std::size_t j, const rolling_hash_powers<M, P>& powers)
    { return ((h[j]-h[i-1])*powers.p_inv[i-1]).value(); }

    [[nodiscard]] int hash() const
    { return h.back().value(); }

private:
    std::vector<mint> h; // 1-indexed
};

}
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string a, b; std::cin >> a >> b;
    int n {static_cast<int>(a.size())};
    int m {static_cast<int>(b.size())};
    if (m > n) { std::cout << 0 << '\n'; return 0; }

    peria::rolling_hash_powers<peria::mint::MOD, 31> rhp {static_cast<std::size_t>(n)};
    peria::rolling_hash rh {a, rhp};
    int pattern_hash {peria::rolling_hash{b, rhp}.hash()};
    int ans {};
    for (int i{}; i+m-1<n; ++i) {
        const auto l {i+1};
        const auto r {i+m-1+1};
        if (pattern_hash == rh.sub_hash(l, r, rhp)) {
            ++ans;
        }
    }
    std::cout << ans << '\n';
    return 0;
}

