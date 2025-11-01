#include <iostream>
#include <map>
#include <set>
#include <limits>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int64_t INF {numeric_limits<int64_t>::max()};
    int n; cin >> n;
    set<int64_t> st;
    map<int64_t, int64_t> mp;
    st.insert(0);
    mp[0] = INF;
    int64_t ans {};
    for (int i{}; i<n; ++i) {
        int64_t a; cin >> a;
        auto it {st.insert(a).first};
        ++it;
        int64_t r {INF};
        if (it != st.end()) {
            r = *it;
        }
        --it; --it;
        int64_t l {*it};
        const auto mn {min(std::abs(a-l), std::abs(a-r))};
        mp[a] = mn;
        ans += mn;
        if (mp[l]>std::abs(a-l)) {
            if (mp[l] == INF) {
                ans += std::abs(a-l);
            }
            else {
                ans += (std::abs(a-l)-mp[l]);
            }
            mp[l] = std::abs(a-l);
        }
        if (r!=INF && mp[r]>std::abs(a-r)) {
            if (mp[r] == INF) {
                ans += std::abs(a-r);
            }
            else {
                ans += (std::abs(a-r)-mp[r]);
            }
            mp[r] = std::abs(a-r);
        }
        cout << ans << '\n';
    }

    return 0;
}

