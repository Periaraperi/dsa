#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    struct point {
        int i{};
        int j{};
    };
    vector<point> points(n);
    int mn_i{numeric_limits<int>::max()}, mx_i{numeric_limits<int>::min()};
    int mn_j{numeric_limits<int>::max()}, mx_j{numeric_limits<int>::min()};
    for (auto &[i, j]:points) {
        cin >> i >> j;
        mn_i = min(mn_i, i);
        mx_i = max(mx_i, i);
        mn_j = min(mn_j, j);
        mx_j = max(mx_j, j);
    }

    point dst {(mn_i+mx_i)/2, (mn_j+mx_j)/2};
    int ans {};
    for (const auto& [i, j]:points) {
        int di {abs(i-dst.i)};
        int dj {abs(j-dst.j)};
        ans = max(ans, max(di, dj));
    }
    cout << ans << '\n';

    return 0;
}

