#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n);
        multiset<int> st;
        for (auto& i:a) { 
            cin >> i; 
            st.insert(i);
        }
        for (auto& i:b) cin >> i;

        int k{};
        for (const auto& i:b) {
            int d {m-i};
            auto it {st.lower_bound(d)};
            if (it == st.end() && !st.empty()) --it;
            if (*it + i >= m) {
                ++k;
                st.erase(it);
            }
        }

        int64_t ans{};
        for (int i{}; i<n; ++i) {
            ans += a[i]+b[i];
        }
        ans -= (int64_t)k*m;
        cout << ans << '\n';
    }

    return 0;
}

