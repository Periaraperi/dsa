#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int64_t MX {static_cast<int64_t>(1e12)};
    constexpr int64_t SQRT_MX {static_cast<int64_t>(1e6)};
    vector<bool> is_prime(static_cast<int>(1e6+1), true);
    vector<int64_t> primes;
    {
        is_prime[0] = is_prime[1] = false;
        const int64_t n {static_cast<int64_t>(1e6)};
        for (int64_t i{2}; i<=n; ++i) {
            if (is_prime[i]) {
                primes.emplace_back(i);
                for (int64_t j{i*i}; j<=n; j+=i) {
                    is_prime[j] = false;
                }
            }
        }
    }

    vector<int64_t> nums;
    const int n {static_cast<int>(primes.size())};

    for (int i{}; i<n-1; ++i) {
        for (int j{i+1}; j<n; ++j) {
            auto p1 {primes[i]};
            auto p2 {primes[j]};
            if (p1*p2 > SQRT_MX) break;
            auto x {p1*p1};
            for (int k1{}; k1<=60; k1+=2) {
                auto y {p2*p2};
                if (x*y > MX) break;
                for (int k2{}; k2<=60; k2+=2) {
                    if (x*y > MX) break;
                    nums.emplace_back(x*y);
                    if (y*p2 > MX || y*p2*p2 > MX) break;
                    y = y*p2*p2;
                }
                if (x*p1 > MX || x*p1*p1 > MX) break;
                x = x*p1*p1;
            }
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int t{1}; cin >> t;
    while (t--) {
        int64_t a; cin >> a;
        auto it {lower_bound(nums.begin(), nums.end(), a)};
        const auto m {*it};
        if (m == a) cout << a << '\n';
        else cout << *(--it) << '\n';
    }
    return 0;
}
