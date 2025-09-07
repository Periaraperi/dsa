#include <iostream>
 
using namespace std;

int64_t bin_pow(int64_t a, int64_t b, int64_t m)
{
    int64_t res {1};
    while (b > 0) {
        if (b%2 == 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return res%m;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int64_t MOD {998244353};
    const auto mod_inverse_two {bin_pow(2, MOD-2, MOD)};

    int64_t N; cin >> N;
    auto n {N%MOD};
    int64_t ans {(((n*(n-1)%MOD)*mod_inverse_two)%MOD + N)%MOD}; // all pairs where a>b + pairs where a == b

    int64_t i {1};
    while (i<=N) {
        const auto q {N/i};
        const auto j {N/q};
        auto bad_pairs {(((j-i+1)%MOD)*(q%MOD))%MOD}; // bad pairs where b divides a
        ans -= bad_pairs;
        if (ans < 0) ans += MOD;
        ans %= MOD;
        i = j+1;
    }

    cout << ans << '\n';
    return 0;
}

