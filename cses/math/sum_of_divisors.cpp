#include <iostream>
 
using namespace std;

int bin_pow(int64_t a, int64_t b, int m)
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

    constexpr int MOD {static_cast<int>(1e9+7)};
    const auto mod_inverse_two {bin_pow(2, MOD-2, MOD)};

    auto range_sum = [mod_inverse_two](int64_t l, int64_t r) -> int64_t {
        l %= MOD;
        r %= MOD;
        return (((((r*(r+1)-l*(l-1)))%MOD + MOD)%MOD)*mod_inverse_two)%MOD;
    };

    int64_t n; cin >> n;
    int64_t ans {};
    int64_t i {1};
    while (i<=n) { // at most 2*sqrt(n) distinct n/i for i from [1, n]
        auto q {n/i};
        auto j {n/q};
        // numbers from [i, j] have same q. Answer increases by q*SUM[i ... j]
        ans = (ans+(range_sum(i, j)*q))%MOD;
        i = j+1;
    }
    cout << ans << '\n';
    return 0;
}

