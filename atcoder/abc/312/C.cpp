#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;

    int64_t lo = 0;
    int64_t hi = 1e9+2;
    auto ans = hi;
    while (lo<=hi) {
        int64_t mid = (lo+hi)/2;
        int x = 0;
        int y = 0;
        for (const auto& i:a) {
            if (i<=mid) ++x;
        }
        for (const auto& i:b) {
            if (i>=mid) ++y;
        }
        if (x>=y) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << '\n';

    return 0;
}

