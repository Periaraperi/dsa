#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    int max_elem {};
    for (auto& i:v) {
        cin >> i;
        max_elem = max(max_elem, i);
    }
    vector<vector<int>> f(max_elem+1);
    for (int i{}; i<n; ++i) {
        f[v[i]].emplace_back(i);
    }
    constexpr int INF {numeric_limits<int>::max()};
    int ans {INF};
    for (int i{}; i<=max_elem; ++i) {
        if (f[i].empty() || f[i].size() == 1) continue;
        int len {INF};
        for (int j{1}; j<static_cast<int>(f[i].size()); ++j) {
            len = min(len, f[i][j]-f[i][j-1]+1);
        }
        ans = min(ans, len);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
    return 0;
}

