#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

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

    [[nodiscard]] friend constexpr modint operator+(const modint& rhs, int64_t x) noexcept
    { return rhs+modint{x}; }

    [[nodiscard]] friend constexpr modint operator-(const modint& lhs, const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(lhs.value_)-static_cast<int64_t>(rhs.value_)+M)%M}; }

    [[nodiscard]] friend constexpr modint operator-(int64_t x, const modint& rhs) noexcept
    { return modint{x}-rhs; }

    [[nodiscard]] friend constexpr modint operator-(const modint& rhs, int64_t x) noexcept
    { return rhs-modint{x}; }

    [[nodiscard]] friend constexpr modint operator*(const modint& lhs, const modint& rhs) noexcept
    { return modint{(static_cast<int64_t>(lhs.value_)*static_cast<int64_t>(rhs.value_))%M}; }

    [[nodiscard]] friend constexpr modint operator*(int64_t x, const modint& rhs) noexcept
    { return modint{x}*rhs; }

    [[nodiscard]] friend constexpr modint operator*(const modint& rhs, int64_t x) noexcept
    { return rhs*modint{x}; }

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1}; cin >> t;

    while (t--) {
        int64_t N, K; cin >> N >> K;

        auto to_binary = [](int64_t x) {
            vector<int> bin; bin.reserve(60);
            while (x>0) {
                bin.emplace_back(x%2);
                x/=2;
            }
            reverse(bin.begin(), bin.end());
            return bin;
        };

        const auto bin {to_binary(N)};
        const auto len {static_cast<int>(bin.size())};

        peria::combinations combs{len+1};

        int first_one{len}; // index of leftmost 1
        for (int i{}; i<len; ++i) {
            if (bin[i]==1) {
                first_one = i;
                break;
            }
        }

        // This many good combinations.
        // 100000000001000000100000010000000001111000011001
        // 1__________0[ segment_len choose k-1           ]
        // 1__________1______0[ segment_len choose k-2    ]
        // 1__________1______1______0[ seglen choose k-3  ]
        // and so on
        //
        // Solution:
        // For each set bit j in N assume that it is 0 and count contribution for each i-th bit after j, when taking k set bits
        // After this assume that j-th bit is set to 1, this means that we can't set bits between j-th and (j+1)-th set bits because number will be more than N.
        // So assume that (j+1)-th bit is 0 and solve same contribution problem to the left of (j+1) + 1 for k-1, and so on.

        // following calculates cumulative sum of i-th bit. i-th bits contribution + contrib of already set bits to the left (given as powers_of_two vector).
        auto cum_sum = [&combs, l=len] (int left, int k, const vector<peria::mint>& powers_of_two) -> peria::mint {
            if (k<0) return {};

            peria::mint contribution {}; 
            for (int i{left}; i<l; ++i) {
                // assume that i-th bit is set.
                // i-th bit will contribute to ans by taking C(len1, 0)*C(len2, k-1) + C(len1, 1)*C(len2, k-2) + ... + C(len1, k-1)*C(len2, 0)
                for (int j{0}; j<=k-1; ++j) {
                    const auto len_left {i-left};
                    const auto len_right {l-i-1};
                    const auto count_left {combs.binom(len_left, j)};
                    const auto count_right {combs.binom(len_right, (k-1)-j)};
                    const auto count {(count_left*count_right)};
                    contribution += (count*peria::mint{1LL<<(l-i-1LL)});
                }
            }

            const auto total_combs {combs.binom(l-left, k)};
            for (const auto& p:powers_of_two) {
                contribution += (total_combs*p);
            }
            return contribution;
        };

        // get index of next 1 in bin after i
        // can also precalculate this, but len of bin is at most 60 so ...
        auto get_next_one = [&bin, l=len](int i) {
            for (int j{i+1}; j<l; ++j) {
                if (bin[j]==1) return j;
            }
            return l;
        };

        peria::mint ans {};
        vector<peria::mint> powers_of_two;
        for (int i{first_one}, j{0}; i<len; i=get_next_one(i), ++j) {
            ans += cum_sum(i+1, K-j, powers_of_two);
            powers_of_two.emplace_back(peria::mint{1LL<<(len-i-1LL)});
        }

        // this if makes sure that rightmost set bit in N is also counted. if popcount(n) == k the upper loop will skip it.
        if (static_cast<int>(powers_of_two.size()) == K && std::popcount(static_cast<unsigned long long>(N)) == K) { // CAREFUL with long long
            for (const auto& p:powers_of_two) {
                ans += p;
            }
        }
        cout << ans.value() << '\n';
    }
    return 0;
}

