#include <cstdint>
#include <vector>

namespace peria {

template<int M>
struct modint;

using mint = peria::modint<1000000007>;
//using mint = peria::modint<998244353>;

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

struct combinations {
    explicit combinations(int n)
        :fact(n+1), fact_inv(n+1)
    {
        fact[0] = mint{1};
        for (int i{1}; i<=n; ++i) {
            fact[i] = (i*fact[i-1]);
        }
        fact_inv[0] = mint{1};
        for (int i{1}; i<=n; ++i) {
            fact_inv[i] = fact[i].inverse();
        }
    }

    [[nodiscard]]
    mint binom(int n, int k)
    {
        if (n<k || k<0) return {};
        return fact[n]*(fact_inv[k]*fact_inv[n-k]);
    }

private:
    std::vector<mint> fact;
    std::vector<mint> fact_inv;
};

}
 
int main() 
{
    return 0;
}

