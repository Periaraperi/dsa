#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int64_t> v(n+1);
    for (int i{1}; i<=n; ++i) cin >> v[i];

    /*  brute force aproach (NQ)
        while (q--) {
            int l, r; cin >> l >> r;
            int64_t ans {};
            for (int i{l}; i<=r; ++i) {
                ans += v[i]*(i-l+1)*(r-i+1);
            }
            cout << ans << '\n';
        }
    */

    // the following should work:
    // above brute force can be calculated using 3 prefix sums arrays.
    // for range [l, r], ans = SUM v[i]*(i-l+1)*(r-i+1), where i is in range [l, r]
    // expanding parans, we get: SUM( v[i]*(-i^2) + (r+l)*i*v[i] + (1+r)(1-l)*v[i])
    // we can rewrite above SUM in 3 different SUMs and pull out constants.
    // Final SUMs: (r+l)SUM(v[i]*i) - SUM(v[i]*i^2) + (1+r)(1-l)SUM(v[i])

    vector<int64_t> pref_sum(n+1);
    vector<int64_t> pref_sum_with_index(n+1);
    vector<int64_t> pref_sum_with_index_squared(n+1);
    for (int i{1}; i<=n; ++i) {
        pref_sum[i] = pref_sum[i-1]+v[i];
        pref_sum_with_index[i] = pref_sum_with_index[i-1]+v[i]*i;
        pref_sum_with_index_squared[i] = pref_sum_with_index_squared[i-1]+v[i]*i*i;
    }

    while (q--) {
        int64_t l, r; cin >> l >> r;
        const auto a {pref_sum_with_index[r]-pref_sum_with_index[l-1]};
        const auto b {pref_sum_with_index_squared[r]-pref_sum_with_index_squared[l-1]};
        const auto c {pref_sum[r]-pref_sum[l-1]};
        cout << (r+l)*a - b + (1+r)*(1-l)*c << '\n';
    }
    return 0;
}
