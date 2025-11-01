#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector<int> pa(n+1, 0);
    vector<int> pb(n+1, 0);
    for (int i{1}; i<=n; ++i) {
        int x {};
        int y {};
        if (s[i-1] == 'a') x = 1;
        else               y = 1;
        pa[i] = pa[i-1]+x;
        pb[i] = pb[i-1]+y;
    }
    int64_t ans {};
    for (int i{1}; i<=n; ++i) {
        auto x {pa[i-1]+a};
        auto y {pb[i-1]+b};
        const int64_t la {static_cast<int64_t>(lower_bound(pa.begin(), pa.end(), x)-pa.begin())};
        const int64_t rb {static_cast<int64_t>(lower_bound(pb.begin(), pb.end(), y)-pb.begin()) - 1};
        if (rb>=la) ans += (rb-la+1);
    }
    cout << ans << '\n';
    return 0;
}

