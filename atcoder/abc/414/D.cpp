#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;

    vector<int64_t> v(n);
    for (auto& i:v) cin >> i;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    n = (int)v.size();
    if (m >= n) {
        cout << 0 << '\n';
    }
    else {
        vector<int64_t> dis(n-1);
        for (int i{1}; i<n; ++i) {
            dis[i-1] = v[i]-v[i-1];
        }
        sort(dis.begin(), dis.end());
        int64_t ans{};
        for (int i{}; i<n-m; ++i) {
            ans += dis[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
