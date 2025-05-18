#include <iostream>
#include <vector>
 
using namespace std;

constexpr int64_t MOD {998244353};
vector<int64_t> fact;
vector<int64_t> fact_inv;

int64_t bin_pow(int64_t a, int64_t b)
{
    int64_t res {1};
    while (b > 0) {
        if (b%2 == 1) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }
    return res;
}

void precomp(int64_t total)
{
    fact.resize(total+1);
    fact[0] = 1;
    for (int64_t i{1}; i<=total; ++i) {
        fact[i] = (i*fact[i-1])%MOD;
    }

    fact_inv.resize(total+1);
    fact_inv[0] = 1;
    for (int64_t i{1}; i<=total; ++i) {
        fact_inv[i] = bin_pow(fact[i], MOD-2);
    }
}

int64_t binom(int64_t n, int64_t k)
{
    if (n < k) return 0;
    return (fact[n]*((fact_inv[k]*fact_inv[n-k])%MOD))%MOD;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t A, O, B, G; cin >> A >> O >> B >> G;
    int64_t total {A+O+B+G};
    precomp(total);
    
    int64_t ans {};
    for (int64_t i{}; i<=B; ++i) {
        int64_t total_to_the_right {B-i+G-1};
        int64_t l {binom(A+O+i, O)};
        int64_t r {(binom(total_to_the_right, B-i) * binom(total_to_the_right-(B-i), G-1))%MOD};
        ans = (ans + (l*r)%MOD);
    }
    cout << ans%MOD << '\n';

    return 0;
}
