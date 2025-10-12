#include <iostream>
 
using namespace std;

namespace peria {

template<int M>
struct modint;

using mint = peria::modint<998244353>;

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

}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr auto mod_inverse_two {peria::mint{2}.inverse()};

    int64_t N; cin >> N;
    auto n {peria::mint{N}};
    auto ans {(n*(n-1))*mod_inverse_two + n}; // all pairs where a>b + pairs where a == b

    int64_t i {1};
    while (i<=N) {
        const auto q {N/i};
        const auto j {N/q};
        const auto bad_pairs {peria::mint{j-i+1}*q}; // bad pairs where b divides a
        ans -= bad_pairs;
        i = j+1;
    }
    cout << ans.value() << '\n';
    return 0;
}

