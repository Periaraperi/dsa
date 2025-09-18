#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

using namespace std;

namespace peria {
// TODO: implement my modint struct not to go insane with long long bugs.

[[nodiscard]]
int64_t bin_pow(int64_t a, int64_t b, int64_t m)
{
    int64_t res{1};
    while (b>0) {
        if (b%2==1) res = (res*a)%m;
        a = (a*a)%m;
        b /= 2;
    }
    return res;
}

template <int64_t M>
struct combinations {
    explicit combinations(int n)
        :fact(n+1), fact_inv(n+1)
    {
        fact[0] = 1;
        for (int64_t i{1}; i<=n; ++i) {
            fact[i] = (i*fact[i-1])%M;
        }
        fact_inv[0] = 1;
        for (int64_t i{1}; i<=n; ++i) {
            fact_inv[i] = bin_pow(fact[i], M-2, M);
        }
    }

    [[nodiscard]]
    int64_t binom(int n, int k)
    {
        if (n<k || k<0) return 0;
        return (fact[n]*((fact_inv[k]*fact_inv[n-k])%M))%M;
    }
private:
    vector<int64_t> fact;
    vector<int64_t> fact_inv;
};

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MOD {998244353};
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

        peria::combinations<MOD> combs{len+1};

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
        auto cum_sum = [&combs, l=len] (int left, int k, const vector<int64_t>& powers_of_two) -> int64_t {
            if (k<0) return 0;

            int64_t contribution {}; 
            for (int i{left}; i<l; ++i) {
                // assume that i-th bit is set.
                // i-th bit will contribute to ans by taking C(len1, 0)*C(len2, k-1) + C(len1, 1)*C(len2, k-2) + ... + C(len1, k-1)*C(len2, 0)
                for (int j{0}; j<=k-1; ++j) {
                    const auto len_left {i-left};
                    const auto len_right {l-i-1};
                    const auto count_left {combs.binom(len_left, j)%MOD};
                    const auto count_right {combs.binom(len_right, (k-1)-j)%MOD};
                    const auto count {(count_left*count_right)%MOD};
                    contribution += (count*((1LL<<(l-i-1LL))%MOD)%MOD); // CAREFUL with long longs and MODS !!!!!!!!!!!!
                    contribution %= MOD;
                }
            }

            const auto total_combs {combs.binom(l-left, k)%MOD};
            for (const auto& p:powers_of_two) {
                contribution += ((total_combs*p)%MOD);
                contribution %= MOD;
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

        int64_t ans {};
        vector<int64_t> powers_of_two;
        for (int i{first_one}, j{0}; i<len; i=get_next_one(i), ++j) {
            ans += cum_sum(i+1, K-j, powers_of_two);
            ans %= MOD;
            powers_of_two.emplace_back((1LL<<(len-i-1LL))%MOD); // CAREFUL with long longs and MODS !!!!!!!!!!!!
        }

        // this if makes sure that rightmost set bit in N is also counted. if popcount(n) == k the upper loop will skip it.
        if (static_cast<int>(powers_of_two.size()) == K && std::popcount(static_cast<unsigned long long>(N)) == K) { // CAREFUL with long longs and MODS !!!!!!!!!!!!
            for (const auto& p:powers_of_two) {
                ans += p;
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

