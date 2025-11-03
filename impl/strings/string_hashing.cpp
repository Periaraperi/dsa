#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>

/*
H(s) = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1)
     = SUM (s[i]*p^i) where 0<=i<=s.len-1
     since powers of p and sum may be very big, compute everything modulo M.

H(s) = (s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1)) mod M
     = SUM ((s[i]*p^i)mod M) where 0<=i<=s.len-1

p and M are some positive integers.
We want to minimize hash collisions, so take M as a large number.
2^64 (ull) is viable choice, but there exists mechanisms to break it
           and it is independent of choice of p.

In practice, p and M are usually prime numbers, because they give better results.
p is commonly around the size of alphabet

use ascii values for characters for now.

Some use cases:
- We can use string hashing to compare 2 strings in O(1).
- We can check number of duplicate strings in a list of strings.
- We can calculate any substring hash in O(1) with similar idea as prefix_sums.
  But this approach requires division with modular arithmetic, so we need to calculate mod inverses
  for powers. We can precompute this during rolling_hash struct initialization.
  Additionally there is a trick to prevent mod inverses.
- We can find number of distinct sub-strings in a string.
- We can use rolling hashing approach to find occurences of pattern in a string.
  Rabin-Karp is popular algorithm which implements this approach.

notes:
- to minimize collisions, especially when we compare many strings with each other, we can use second hash for each string
  with different P and/or Mod values.
*/

namespace peria {

template<int M>
struct modint;

using mint = modint<1000000009>;

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

struct dup_info {
    std::string s;
    int count {};
};

// search for duplicate strings in a list of strings.
[[nodiscard]]
std::vector<dup_info> count_duplicates(const std::vector<std::string>& strs)
{
    const peria::rolling_hash_powers<peria::mint::MOD, 31> rhp {10000}; // only using lowercase english letters, hence 31 as P
    const int n {static_cast<int>(strs.size())};

    //                                 hash   string's index 
    std::vector<std::pair<peria::rolling_hash, std::size_t>> hashes; hashes.reserve(n);
    for (std::size_t i{}; i<strs.size(); ++i) {
        hashes.emplace_back(std::make_pair(peria::rolling_hash{strs[i], rhp}, i));
    }

    // Don't sort strs, because string comparison by default will be linear, so we will get
    // time complexity of O(n*log(n)*m), where n is length of list, and m is the length of largest string.
    // By getting their hashes, and sorting on hashes we remove extra (*m).
    // So we get O(n*m + n*log(n)) --> nlogn for sorting and n*m for hash precomputation (for iterating over each string).
    std::sort(hashes.begin(), hashes.end(), [](const auto& a, const auto& b) { return a.first.hash() < b.first.hash(); }); 

    std::vector<dup_info> ans; ans.reserve(256);
    for (int i{1}; i<n; ++i) {
        if (hashes[i].first.hash() == hashes[i-1].first.hash()) {
            ans.emplace_back(dup_info{strs[hashes[i].second], 1});
            while (i<n && hashes[i].first.hash() == hashes[i-1].first.hash()) {
                ++ans.back().count;
                ++i;
            }
        }
    }
    return ans;
}

[[nodiscard]]
int number_of_distinct_substrings(const std::string& s)
{
    peria::rolling_hash_powers<peria::mint::MOD, 31> rhp {s.size()};
    peria::rolling_hash rh {s, rhp};

    const int n {static_cast<int>(s.size())};
    
    int ans {};
    for (int len{1}; len<=n; ++len) {
        std::unordered_set<int> unique_hashes; // store length len substring hashes.
        for (int i{}; i+len-1<n; ++i) {
            const auto l {i+1}; // 1-based indexing
            const auto r {i+len-1+1}; // 1-based indexing
            unique_hashes.insert(rh.sub_hash(l, r, rhp));
        }
        ans += unique_hashes.size();
    }
    
    return ans;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {
        std::cout << "String Dup Test\n";
        std::vector<std::string> strs {"periaraperi", "laga", "laggert", "abc", "abacaba", "abc", 
                                       "laga", "peria", "poyera", "abc", "laga", "poyera", "daba", "baba", "caba"};

        const auto dups {count_duplicates(strs)};
        for (const auto& [s, count]:dups) {
            std::cout << s << " - " << count << '\n';
        }
    }

    {
        std::cout << "\nDistinct SubStrings Test\n";
        std::string str{"abacabac"};
        std::cout << "Str = " << str << " - " << number_of_distinct_substrings(str) << '\n';
    }
    
    return 0;
}

