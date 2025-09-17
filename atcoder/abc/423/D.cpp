#include <iostream>
#include <map>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64_t k;
    cin >> n >> k;
    struct info {
        int64_t a {};
        int64_t b {};
        int64_t c {};
    };
    vector<info> v(n);
    for (auto& [a, b, c]:v) cin >> a >> b >> c;

    map<int64_t, int64_t> mp;
    int64_t t{};
    vector<int64_t> ans(n);
    for (int i{}; i<n; ++i) {
        ans[i] = max(v[i].a, t);
        while (k<v[i].c) {
            const auto [time, count] {*mp.begin()};
            k += count;
            ans[i] = max(ans[i], time);
            mp.erase(mp.begin());
        }
        t = ans[i];
        mp[ans[i]+v[i].b] += v[i].c;
        k -= v[i].c;
    }

    for (const auto& i:ans) cout << i << '\n'; 

    return 0;
}

